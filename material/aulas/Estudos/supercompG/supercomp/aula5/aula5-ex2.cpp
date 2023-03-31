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
    int n = 0;
    int w =0;
    vector<item> items;
    vector<item> mochila;

    cin >> n >> w; 
    items.reserve(n);
    double peso,valor;

    
    for(int i = 0 ; i<n; i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i,peso,valor});
     }
     
     sort(items.begin(),items.end(),my_compare); //sinvariante - elementos ordenado pelo peso (eh um ponto de certeza)
     
     peso = 0;
     valor = 0;
     for(auto& el: items){
         if(el.peso + peso <= w){
             mochila.push_back(el);
             peso += el.peso;
             valor +=el.valor;
         }
     }

     //ordenando para imprimir
     sort(mochila.begin(),mochila.end(),[](auto&i, auto&j){return i.id < j.id;});
     cout << valor << endl;
    //  for(auto& el: mochila){
    //      cout << el.id << " ";
    //  }
    
    
    return 0;
}
bool my_compare(item a,item b){
    return a.peso < b.peso; //ordem crescente se fosse crescente seria a < b 
}

// g++ -Wall -O3 ex2_valor.cpp -o ex2_valor