#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;


int main () {
    uniform_real_distribution<double> distribution(0.0,1.0);// sortear pontos entre 0 e 1

    long N = 100000000; //100000
    const int NUM_THREADS = 4; // número de threads a serem usadas
    const int CHUNK_SIZE = N / NUM_THREADS; // número de iterações por thread
    double sum = 0;
    double tdata;
    tdata = omp_get_wtime();
    vector<double> x(N), y(N);

    #pragma omp parallel num_threads(NUM_THREADS)
    {
        // identificador da thread
        int tid = omp_get_thread_num();

        default_random_engine generator;
        generator.seed(10 + tid); // Seed baseada no numero da thread

        // cada thread processa seu próprio chunk
        for (int i = tid * CHUNK_SIZE; i < (tid + 1) * CHUNK_SIZE; i++){
            x[i] = distribution(generator);
            y[i] = distribution(generator);

            if ((pow(x[i],2) + pow(y[i],2)) <= 1 )
                #pragma omp atomic
                sum +=1;
        }
    }

    sum *= 4;
    sum /= N;

    tdata = omp_get_wtime() - tdata;
    cout << "Soma: " << sum << endl;
    cout << "tempo em segundos: " << tdata << endl;
    return 0;
}



// Rodar: g++ -g -Wall -fopenmp -o montecarloPC2_V pi_montecarloParCerto2-Vetor.cpp

// Versão Paralela (seed consertado)
// Soma: 3.14151
// tempo em segundos: 9.73382




// ------ Obs.:-----------
// - No codigo, teve que ter um valor de N maior que da versão sequencial para chegar em um valor mais próximo de PI
// - O modificador "reduction" cria uma variável compartilhada "sum" que é inicializada para zero em cada thread e atualizada
// com a soma dos valores calculados por cada thread. O operador "+:" especifica que a operação de redução é a soma.
