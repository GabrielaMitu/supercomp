#include <random>
#include<iostream>
#include<math.h>
#include<iomanip>      // std::setprecision
using namespace std;

int main(){
    double num=0;
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 1.0);
    for (int i=0; i<10; i++){
        num = distribution(generator); // gera número
        cout << num << endl;
    }
    
    return 0;
}

// g++ -Wall -O3 ex1.cpp -o ex1


