// Versao Prof do precoAcoes.cu

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <algorithm>

int main() {
    thrust::host_vector<double> vcpu(2518); // cria host_vector
    for(int i = 0; i< 2518; i++)
        std::cin >> vcpu[i]; // jogando dentro da cpu (não lẽ direto na GPU pq é ruim)
    thrust::device_vector<double>vgpu(vcpu); // coloca na GPU

    // qual o valor medio dos elementos
    double media = thrust::reduce(vgpu.begin(), vgpu.end(), (double)0, thrust::plus<double>()) / vgpu.size(); // reducao do vetor da gpu, reducao é uma soma, valor inicial é double zero
    std::cout << "Média dos elementos = " << media << std::endl;

    thrust::device_vector<double>::iterator last_365 = vgpu.end() - 365; // ultimos 365 dias
    double media365 = thrust::reduce(last_365, vgpu.end(), (double)0, thrust::plus<double>()) / 365;
    std::cout << "Média dos ultimos 365 elementos = " << media365 << std::endl;

    thrust::device_vector<double>::iterator max_elem = thrust::max_element(vgpu.begin(), vgpu.end()); // tem o endereco de memoria aqui
    thrust::device_vector<double>::iterator min_elem = thrust::min_element(vgpu.begin(), vgpu.end());
    std::cout << "Maior elemento = " << *max_elem << std::endl;
    std::cout << "Menor elemento = " << *min_elem << std::endl;

    thrust::device_vector<double>::iterator max_elem365 = thrust::max_element(last_365, vgpu.end()); // tem o endereco de memoria aqui
    thrust::device_vector<double>::iterator min_elem365 = thrust::min_element(last_365, vgpu.end());
    std::cout << "Maior elemento = " << *max_elem365 << std::endl;
    std::cout << "Menor elemento = " << *min_elem365 << std::endl;

    return 0;

}

// cmd (compilar): nvcc -arch=sm_70 -std=c++14 resolucao_reduce.cu -o resolucao
// ./resolucao < stocks.txt