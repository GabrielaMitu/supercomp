#include <iomanip>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <math.h>
#include <iostream>

using namespace std;

static long num_steps = 1024l*1024*1024*2;

#define MIN_BLK  1024*1024*256

double sum = 0;

void pi_r(long Nstart, long Nfinish, double step) {
    long i,iblk;
    if (Nfinish-Nstart < MIN_BLK){
        // cada iteração do loop é executada por uma thread diferente
        #pragma omp parallel for reduction(+:sum) // garante que quando vai executar isso, ele vai estar com o valor do sum. Maneira automatica para criar tasks
        for (i = Nstart; i < Nfinish; i++){
            double x = (i+0.5)*step;
            sum += 4.0/(1.0+x*x); 
        }

    } else {
        iblk = Nfinish-Nstart;

        // Uma thread faz duas tarefas (uma de cada vez)
        #pragma omp single // especifica que um determinado bloco de código deve ser executado por apenas uma thread em um conjunto de threads paralelas. Somente uma thread executa o bloco de código, enquanto as outras aguardam a conclusão antes de continuar.
            #pragma omp task
            pi_r(Nstart,         Nfinish-iblk/2,step);

            #pragma omp task
            pi_r(Nfinish-iblk/2, Nfinish,       step);
    }
}

int main () {
    double tdata = omp_get_wtime();
    long i;
    double step, pi;
    double init_time, final_time;
    step = 1.0/(double) num_steps;
    init_time = omp_get_wtime();
    pi_r(0, num_steps, step);
    pi = step * sum;
    final_time = omp_get_wtime() - init_time;

    cout << "for " << num_steps << " steps pi = " << std::setprecision(15) << pi << " in " << final_time << " secs\n";
    tdata = omp_get_wtime() - tdata;
    cout << "tempo em segundos: " << tdata << endl;
}

// Versão usando for parelelo e tasks
// Rodar: g++ -g -Wall -fopenmp -o pi-RT pi_recursivo_Task.cpp

// Antes => tempo em segundos: 11.5569880820003s
// Depois de colocar o pragma omp parallel forfor => tempo em segundos: 1.84628277899992s
