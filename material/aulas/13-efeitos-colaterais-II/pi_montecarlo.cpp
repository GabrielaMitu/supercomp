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

    long N = 100000000; //100000 => mudei para esse N porque só com 100000, não estava chegando ao numero de pi 
    double sum = 0;
    double x,y;
    double tdata;
    tdata = omp_get_wtime();
        for (int i = 0; i < N; i++){
            x = distribution(generator);
            y = distribution(generator);
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


// Rodar: g++ -g -Wall -fopenmp -o montecarlo pi_montecarlo.cpp

// Versão Sequencial
// Soma: 3.14157
// tempo em segundos: 180.209 (não tenho certeza se é isso mesmo ou maior)

