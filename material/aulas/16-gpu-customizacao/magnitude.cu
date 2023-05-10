#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <random>
#include <thrust/device_vector.h> // adicionado
#include <thrust/transform.h> // adicionado
#include <thrust/reduce.h> // adicionado
#include <thrust/functional.h> // adicionado

using namespace std::chrono;

// Functor para calcular o quadrado (transform neste caso é elevação dos elementos do vetor ao quadrado)
struct square {
    __host__ __device__ // CPU e GPU
    float operator()(float x) const {
        return x * x;
    }
};

// feito para imprimir o tempo de execução de uma parte do código
void reportTime(const char* msg, steady_clock::duration span) {
    auto ms = duration_cast<milliseconds>(span);
    std::cout << msg << " - levou - " <<
    ms.count() << " milisegundos" << std::endl;
}

/* // IMPLEMENTE O CALCULO DA MAGNITUDE COM THRUST
float magnitude(thrust::device_vector<float>& v_d) {
    float result;

    // faz a transformação square
    thrust::transform(v_d.begin(), v_d.end(), v_d.begin(), square()); // aplica a transformação da função square para elevar os elementos ao quadrado

    // faz a redução para obter a magnitude
    result = std::sqrt(thrust::reduce(v_d.begin(), v_d.end(), 0.0f, thrust::plus<float>())); // soma dos elementos do vetor usando a função plus


    return result;
} */

// IMPLEMENTE O CALCULO DA MAGNITUDE COM THRUST E FUSION PARA OTIMIZAR TRANSFORM E REDUCE
float magnitude(thrust::device_vector<float>& v_d) {
    float result;

    // faz a redução para obter a magnitude
    result = std::sqrt(thrust::transform_reduce(v_d.begin(), v_d.end(), square(), 0.0f, thrust::plus<float>())); // soma dos elementos do vetor usando a função plus

    return result;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << argv[0] << ": numero invalido de argumentos\n"; 
        std::cerr << "uso: " << argv[0] << "  tamanho do vetor\n"; 
        return 1;
    }
    int n = std::atoi(argv[1]); //numero de elementos
    steady_clock::time_point ts, te;

    // Cria um vetor em thrust na memória da GPU com n elementos do tipo float
    thrust::device_vector<float> v_d(n); 

    // Iniciliza o vetor
    ts = steady_clock::now();

    std::generate(v_d.begin(), v_d.end(), std::rand); // usado para preencher o vetor com valores aleatórios

    te = steady_clock::now();
    reportTime("Inicializacao", te - ts);

    // Aplica a transformação square
    ts = steady_clock::now();

    float len = magnitude(v_d);

    te = steady_clock::now();
    reportTime("Tempo para calculo", te - ts);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Magnitude : " << sqrt(len) << std::endl;
}

// ---- cmd ----
// nvcc -arch=sm_70 -std=c++14 magnitude.cu -o magnitude
// ./magnitude