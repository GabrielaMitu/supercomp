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
bool my_compare(item a, item b); //assinatura

int main() {
    default_random_engine generator;
    generator.seed(10);

    int n = 0;
    int w =0;
    uniform_real_distribution<double> distribution(0.0,1.0);
    vector<item> mochila;
    vector<item> items;

    cin >> n >> w; 
    items.reserve(n);

    
    items.reserve(n);
    double peso, valor;

    
    for(int i = 0 ; i<n; i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i,peso,valor});
     }
     
     //sinvariante - elementos ordenado pelo peso (eh um ponto de certeza)
     sort(items.begin(),items.end(), [](auto& i, auto& j){return i.valor > j.valor;}); 
     
     peso = 0;
     valor = 0;
     int i = 1;
     for(auto& el: items){
         
            if(el.peso + peso <= w){
                mochila.push_back(el);
                peso += el.peso;
                valor += el.valor;
            
            }
            if (distribution(generator) > 0.75 && i<n){
                uniform_int_distribution<int> distribution(i,n-1);
                int p = distribution(generator);
                if (items[p].peso + peso <= w){
                    mochila.push_back(items[p]);
                    peso = peso + items[p].peso;
                    valor = valor + items[p].valor;

                    items.erase(items.begin()+p-1);
                    n=n-1;

                }
            }
            i=i+1;
     }

     //ordenando para imprimir
     sort(mochila.begin(),mochila.end(),[](auto&i, auto&j){return i.id < j.id;});
     cout << peso << " " << valor << " 0" << "\n";

     for (auto& el : mochila){
         cout << el.id << " ";
     }

     cout << peso << " " << valor << " 0" << endl;
     for(auto& el: mochila){
         cout << el.id << " ";
     }
    
    
    return 0;
}
bool my_compare(item a,item b){
    return a.peso < b.peso; //ordem crescente se fosse crescente seria a < b 
}

// g++ -Wall -O3 ex1.cpp -o ex1