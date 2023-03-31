#include<iostream>
#include<math.h>
#include<iomanip>      // std::setprecision
using namespace std;

int main(){
    int n=0;
    double s = 0.0;
    cout << "Digite um número" << endl;
    cin >> n;
    for(int e=0; e<n; e++)
        s = s + 1/(pow(2,e));
    cout << fixed << setprecision(15) << s << endl;
    
    return 0;
}

// g++ -Wall -O3 ex1-correcao.cpp -o ex1-correcao