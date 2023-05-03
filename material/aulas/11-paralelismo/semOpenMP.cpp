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
    int nthreads = omp_get_max_threads();
    cout << "Número de threads: " << nthreads << endl;

    for (i = 0; i < STEP; i++) {
        pi += pow(-1,i) / (2*i+1);
    }

    pi = 4.0*pi;
    cout << "valor de pi = " << pi << endl;
    tdata = omp_get_wtime() - tdata;
    cout << "tempo em segundos: " << tdata << endl;

    return 0;
}

// Executa o loop sequencialmente
// Para rodar: g++ -g -Wall -fopenmp -o semMP semOpenMP.cpp

// ----- Resultado -----
// valor de pi = 3.14159
// tempo em segundos: 24.1055
