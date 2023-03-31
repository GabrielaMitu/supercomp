#include<iostream>
#include<math.h>
#include<iomanip>      // std::setprecision
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> vec;
    for (int i = 0; i < n; i++) {
        vec.push_back(i * i);
    }
    cout << "Tamanho do vetor: " << vec.size() << "\n";
    cout << "Primeiro elemento: " << vec.front() << "\n";
    cout << "Último elemento: " << vec.back() << "\n";
    cout << "Elemento 3: " << vec[2] << "\n";

return 0;
}