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
    // o conjunto desses comandos permite gerar um num aleatorio entre 0 e 1 com dist uniforme,
    // utilizado para determinar se um item é add ou nao na mochila
    default_random_engine generator; // gerador de numeros aleatorios
    generator.seed(10); // guarda para ser usado depois
    uniform_real_distribution<double> distribution(0.0,1.0);

    // Variaveis e vetores
    int n = 0; // itens disponiveis
    int w = 0; // capacidate total da mochila
    vector<item> mochila;
    vector<item> items(n);

    cin >> n >> w; 

    double peso, valor;

    
    for(int i = 0 ; i<n; i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i,peso,valor});
     }
     
     //itens ordenados de forma decrescente de valor
     sort(items.begin(),items.end(), [](auto& i, auto& j){return i.valor > j.valor;}); 
     
    cout << "Items size: " << items.size() << endl;


     peso = 0;
     valor = 0;
     int i = 0; // i = 1 // usado para percorrer os itens do vetor "items"
     
     //Apenas metade dos itens serão adicionados na mochila
     for(auto& el: items){
            if (distribution(generator) > 0.5 && i<n){ // ve se o numero aleatorio gerado é maior que 0.5 e i<n
                uniform_int_distribution<int> distribution(i,n); // (i, n-1)// gera um numero aleatorio de i até n-1
                int p = distribution(generator); // guarda resultado na variavel p
                if (items[p].peso + peso <= w){ // verifica se o item escolhido pelo indice p não ultrapassa a capacidade da mochila
                    mochila.push_back(items[p]);
                    peso += items[p].peso;
                    valor += items[p].valor;
                    items.erase(items.begin()+p-1); // item é removido do vetor items
                    n=n-1; // então diminui o numero total de items
                }
            }
            i=i+1;
     }
    // Adiciona os itens que não foram incluídos no loop anterior
    // é necessário para garantir que todos os itens sejam considerados na solução
     for(auto& el: items){
                if (el.peso + peso <= w){ // ve antes se dá para entrar na mochila (dentro da capacidade)
                    mochila.push_back(el);
                    peso += el.peso;
                    valor += el.valor;
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