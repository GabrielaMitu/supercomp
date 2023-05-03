#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <math.h>
#include <iostream>

using namespace std;

double funcao1() {
    sleep(4);
    return 47;
}

double funcao2() {
    sleep(1);
    return -11.5;
}

int main() {
    double tdata = omp_get_wtime();
    double res_func1, res_func2;

    #pragma omp parallel
    {
        // Cria uma tarefa para executar a função funcao1
        #pragma omp single nowait
        {
            #pragma omp task
            {
                res_func1 = funcao1();
                cout << "Thread " << omp_get_thread_num() << ": funcao1 terminou.\n";
            }
        }

        // Cria uma tarefa para executar a função funcao2
        #pragma omp single nowait
        {
            #pragma omp task
            {
                res_func2 = funcao2();
                cout << "Thread " << omp_get_thread_num() << ": funcao2 terminou.\n";
            }
        }
    }

    cout << res_func1 << " " << res_func2 << "\n";
    tdata = omp_get_wtime() - tdata;
    cout << "tempo em segundos: " << tdata << endl;
}

// Versão Paralela
// Rodar: g++ -g -Wall -fopenmp -o ex1 exercicio1.cpp

// tempo em segundos: 4.00079