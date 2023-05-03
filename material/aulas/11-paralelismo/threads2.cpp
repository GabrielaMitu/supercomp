#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
    double tdata = omp_get_wtime();
    long STEP = 1000000000;
    long i;
    double pi = 0;
    cout << "Número de threads: " << "2" << endl;

    #pragma omp parallel for num_threads(2) reduction(+:pi) // compilador paraleliza o loop usando 2 threads
    for (i = 0; i < STEP; i++) {
        pi += pow(-1,i) / (2*i+1);
    }

    pi = 4.0*pi;
    cout << "valor de pi = " << pi << endl;
    tdata = omp_get_wtime() - tdata;
    cout << "tempo em segundos: " << tdata << endl;

    return 0;
}

// Obs.: Usa OpenMP
// Para rodar: g++ -g -Wall -fopenmp -o threads2 threads2.cpp

// ----- Resultado -----
// valor de pi = 3.14159
// tempo em segundos: 12.8026
