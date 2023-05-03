#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct item {
    int id;
    double peso;
    double valor;
};

// usados: conseguir controlar depois quais itens que eu coloquei na mochila

double knapsack(int W, vector<item> items, vector<item>& usados, vector<item>& melhor) {
    double peso = 0.0;
    double valor = 0.0;
    double sem_i = 0.0, com_i = 0.0; // sem_i = sem itens; com_i = com itens
    vector<item> items2 = items;

    // verifica se o vetor de items esta vazio ou capacidade é zero
    if(items.empty() || W == 0) {
        return 0;
    }
    // dois braços da recursao:
    // verifica se o primeiro item da mochila tem peso menor que a capacidade máxima
    if(items[0].peso <= W) {
        usados.push_back(items[0]);
        valor = items[0].valor;
        peso = items[0].peso;
        items.erase(items.begin()); // apaga o primeiro item do vetor de items original
        com_i = knapsack(W - peso, items, usados, melhor); // versão incluindo o item
    }
    items2.erase(items2.begin());
    sem_i = knapsack(W, items2, usados, melhor); // versão não incluindo o item

    double valor_atual = 0.0, valor_melhor = 0.0;
    for(auto& el: usados) {
        valor_atual += el.valor;
    }
    for(auto& el: melhor) {
        valor_melhor += el.valor;
    }
    if (valor_atual > valor_melhor) {
        melhor = usados;
    }
    usados.clear();
    return max(sem_i, valor + com_i);

}

int main() {
    int n = 0;
    int W = 0;
    vector<item> mochila;
    cin >> n >> W;
    vector<item> items, usados, melhor;
    items.reserve(n);
    usados.reserve(n);
    double peso, valor;
    for(int i = 0; i < n; i++) {
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }
    cout << "Resultado " << knapsack(W, items, usados, melhor) << "\n"; 
    for (auto& el: melhor) {
        cout << el.id << " ";
    }
    return 0;
}

// cmd:
// g++ -o buscaExaustiva busca-exaustiva.cpp
// ./buscaExaustiva < "in1.txt"