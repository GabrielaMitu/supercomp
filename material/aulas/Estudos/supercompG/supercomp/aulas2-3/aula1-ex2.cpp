#include<iostream>
#include<math.h>
#include<iomanip>      // std::setprecision
#include<vector>
using namespace std;

int main(){
    int n=0;
    double media = 0.0;
    double desvpad = 0.0;
    cout << "Digite um valor de n" << endl;
    cin >> n;
    vector<double> values;
    for(int e=0; e<n; e++){
        double input;
        cin >> input;
        values.push_back(input);
        media += input;
    }
    media /=n;

    for (auto valor : values){
        desvpad += ((valor-media)*(valor-media));
    }
    desvpad/=n;

    cout << fixed << setprecision(15) << "média: " << media << endl;
    cout << fixed << setprecision(15) << "desvpad" << desvpad << endl;
    
    return 0;
}

// g++ -Wall -O3 ex2-correcao.cpp -o ex2-correcao