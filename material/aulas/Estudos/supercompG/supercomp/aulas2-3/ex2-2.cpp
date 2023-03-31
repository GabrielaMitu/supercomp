#include<iostream>
#include<math.h>
#include<iomanip>      // std::setprecision
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> vec;
    double xi;
    for (int i = 0; i < n; i++) { 
        cin >> xi;
        vec.push_back(xi);
    }

    double mu,s, desvpad;
    s=0;
    for (int i = 1; i <= n; i++) {
        s+=vec[i-1];
    }
    mu=s/n;
    s=0;
    for (int i = 1; i <= n; i++) {
        s+=pow(vec[i-1]-mu,2);
    }
    desvpad = s/n;

    cout << "Tamanho do vetor: " << vec.size() << "\n";
    cout << "mu: " << mu << "\n";
    cout << "desvpad: " << desvpad << "\n";

return 0;
}

// g++ -Wall -O3 ex2-2.cpp -o ex2-2