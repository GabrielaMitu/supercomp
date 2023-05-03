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
    default_random_engine generator;
    generator.seed(10);
    uniform_real_distribution<double> distribution(0.0,1.0); // sortear pontos entre 0 e 1

    long N = 100000000; //100000
    double sum = 0;
    double x,y;
    double tdata;
    tdata = omp_get_wtime();
    #pragma omp parallel for reduction (+:sum) // cria uma equipe de threads, onde cada thread executará uma parte do loop for
        for (int i = 0; i < N; i++){
            #pragma omp critical 
            {
                x = distribution(generator);
                y = distribution(generator);
            }
            if ((pow(x,2) + pow(y,2)) <= 1 )
                sum +=1;
        }

    sum *= 4;
    sum /= N;

    tdata = omp_get_wtime() - tdata;
    cout << "Soma: " << sum << endl;
    cout << "tempo em segundos: " << tdata << endl;
    return 0;
}


// Rodar: g++ -g -Wall -fopenmp -o montecarloP pi_montecarloParalelo.cpp

// Versão Paralela
// Soma: 3.14145
// tempo em segundos: 30.8167

// ------ Obs.:-----------
// - No codigo, teve que ter um valor de N maior que da versão sequencial para chegar em um valor mais próximo de PI
// - O modificador "reduction" cria uma variável compartilhada "sum" que é inicializada para zero em cada thread e atualizada
// com a soma dos valores calculados por cada thread. O operador "+:" especifica que a operação de redução é a soma.
