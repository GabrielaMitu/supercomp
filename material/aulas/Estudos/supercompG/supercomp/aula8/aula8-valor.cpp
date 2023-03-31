#include <iostream>
#include <vector>
#include <cmath>
#include<fstream>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct item{
    int id;
    double peso;
    double valor;
};

double knapSack(int W, vector <item> items){
    
    if (items.empty() || W==0) return 0;

    if (items[0].peso>W){
        items.erase(items.begin());

        return knapSack(W, items);
    }else{
        double valor = items[0].valor;
        double peso = items[0].peso;

        items.erase(items.begin());
        return max(valor +  knapSack(W-peso, items), knapSack(W, items));
    }
}

int main(){
    int n,W;
    cin >> n >> W;
    vector <item> items, usado, melhor;
    items.reserve(n);
    usado.reserve(n);
    double peso, valor;

    for (int i=0; i<n;i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i,peso,valor});
    }

    cout << "RESULTADO = " << knapSack(W, items) << endl;

    for (auto& el : melhor){
        cout << el.id << " " ;
    }



    return 0;
}

 // g++ -Wall -O3 codigo_aula8.cpp -o codigo_aula8