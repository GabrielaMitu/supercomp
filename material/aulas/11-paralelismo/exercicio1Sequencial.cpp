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

    res_func1 = funcao1();
    res_func2 = funcao2();     

    cout << res_func1 << " " << res_func2 << "\n";
    tdata = omp_get_wtime() - tdata;
    cout << "tempo em segundos: " << tdata << endl;
}

// Versão sequencial
// Rodar: g++ -g -Wall -fopenmp -o ex1 exercicio1.cpp

// tempo em segundos: 5.00068