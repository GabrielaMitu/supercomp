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

    #pragma omp parallel for reduction(+:pi)
    for (i = 0; i < STEP; i++) {
        pi += pow(-1,i) / (2*i+1);
    }

    pi = 4.0*pi;
    cout << "valor de pi = " << pi << endl;
    tdata = omp_get_wtime() - tdata;
    cout << "tempo em segundos: " << tdata << endl;

    return 0;
}

//  ----- Obs.: ------
// - Usa OpenMP
// - permite que cada thread tenha sua própria cópia local da variável "pi" e, no final do loop,
// esses valores locais são combinados em um valor único para a variável "pi" usando a operação de soma,
// garantindo assim a consistência do resultado.
// - usa o máximo de threads disponiveis => omp_get_max_threads

// Para rodar: !g++ -g -Wall -fopenmp -o reduction reduction.cpp

// ----- Resultado -----
// valor de pi = 3.14159
// tempo em segundos: 5.69961

