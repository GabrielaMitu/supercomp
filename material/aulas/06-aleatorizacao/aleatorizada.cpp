#include <iostream>
#include <vector>
#include <cmath>
#include<fstream>
#include <bits/stdc++.h>

using namespace std;

struct item{
    int id;
    double peso;
    double valor;
};


int main() {
    default_random_engine generator;
    generator.seed(10);

    int n = 0;
    int w = 0;
    uniform_real_distribution<double> distribution(0.0,1.0);
    vector<item> mochila;
    vector<item> items(n);

    cin >> n >> w; 

    double peso, valor;

    for(int i = 0 ; i<n; i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i,peso,valor});
     }
     
     //sinvariante - elementos ordenado pelo valor (eh um ponto de certeza)
     sort(items.begin(),items.end(), [](auto& i, auto& j){return i.valor > j.valor;}); 
     
     peso = 0;
     valor = 0;
     int i = 1;
     for(auto& el: items){
            if (distribution(generator) > 0.5 && i<n){
                uniform_int_distribution<int> distribution(i,n-1);
                int p = distribution(generator);
                if (items[p].peso + peso <= w){
                    mochila.push_back(items[p]);
                    peso += items[p].peso;
                    valor += items[p].valor;
                    items.erase(items.begin()+p-1);
                    n=n-1;
                }
            }
            i=i+1;
     }

     for(auto& el: items){
                if (el.peso + peso <= w){
                    mochila.push_back(el);
                    peso = peso + el.peso;
                    valor = valor + el.valor;
                    // items.erase(items.begin()+p-1);
                }
     }


     //ordenando para imprimir
     sort(mochila.begin(),mochila.end(),[](auto&i, auto&j){return i.id < j.id;});
     cout << peso << " " << valor << " 0" << "\n";

     for (auto& el : mochila){
         cout << el.id << " ";
     }
    
    
    return 0;
}

// g++ -Wall -O3 ex1.cpp -o ex1