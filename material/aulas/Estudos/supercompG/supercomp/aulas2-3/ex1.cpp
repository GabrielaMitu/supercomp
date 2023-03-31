#include<iostream>
#include<math.h>
#include<iomanip>      // std::setprecision
using namespace std;

int main(){
    double s=0;
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        s+=1/pow(2,i);
    cout << "result: " << s <<endl;

    return 0;
}

// g++ -Wall -O3 ex1.cpp -o ex1