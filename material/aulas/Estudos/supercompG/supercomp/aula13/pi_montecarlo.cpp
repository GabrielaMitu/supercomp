#include <omp.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include<fstream>
#include <bits/stdc++.h>

using namespace std;


int main () {
    default_random_engine generator;
    generator.seed(10);
    uniform_real_distribution<double> distribution(0.0,1.0);
    long N = 10000000;
    double sum=0;
    double x,y;
    double init_time, final_time;
    init_time = omp_get_wtime();
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