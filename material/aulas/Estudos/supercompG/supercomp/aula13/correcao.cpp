#include <omp.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include<fstream>
#include <bits/stdc++.h>

using namespace std;


int main () {
    
    long N = 10000000L;
    double sum=0;
    double x,y;
    double init_time, final_time;
    init_time = omp_get_wtime();

    int n_threads = omp_get_max_threads();
    // vector
 uniform_real_distribution<double> distribution(0.0,1.0);


    #pragma omp parallel for reduction (+:sum)
        for (int i=0; i<N; i++){
            #pragma omp critical 
            {
                x = distribution(generator);
                y = distribution(generator);
            }
            if ( (pow(x,2) + pow(y,2)) <= 1 )
                sum +=1;

        }
    sum*=4;
    sum/=N;
    final_time = omp_get_wtime() - init_time;
    std::cout <<  sum << "  " << final_time << " secs\n";
    return 0;
}

// g++ -Wall -O3 -fopenmp pi_montecarlo.cpp -o pi_montecarlo

// Problema: geracao de seeds é inerentemente sequencial
// vao competir pelo generator
// e a distribuicao tem que ser uniforme (todos podem cair em qualquer lugar)
// genarators tem que ser individuais pra cada thread --> cada um tem um