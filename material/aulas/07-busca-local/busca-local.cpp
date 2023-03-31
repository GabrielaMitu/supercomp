#include<iostream>
#include<vector>
#include<algorithm>
#include <random>
using namespace std;

struct item {
    int id;
    int peso; 
    int valor;
};

int main() {
  default_random_engine generator(100); // seed = 100
  uniform_real_distribution<double> distribution(0.0, 1.0);

  int n = 0;
  int W = 0;
  int melhor_valor = 0;
  int amostras = 40000;

  vector<item> mochila; // mochila atual
  vector<item> melhor_mochila; // melhor mochila encontrada aate agora
  vector<item> items;

  cin >> n >> W;
  items.reserve(n);

  int peso = 0, valor = 0;

  for(int a = 0; a < n; a++) {
    cin >> peso;
    cin >> valor;
    items.push_back({a, peso, valor});
  }

  //aleatoriza o vetor
  random_shuffle(items.begin(), items.end());

  //cria solucoes aleatorias e faz busca local
  for(int c = 0; c < amostras; c++) {
    mochila.clear();
    vector<item> items2;
    items2.reserve(n);
    peso = 0;
    valor = 0;
    // milestone: criando a solucao aleatoria
    for(int i=0; i<n; i++) {
      if(distribution(generator) > 0.5) {
        if (items[i].peso + peso <= W) {
          mochila.push_back(items[i]);
          peso = peso + items[i].peso;
          valor = valor + items[i].valor;
        }
        else {
          // se um item não couber na mochila, é add no items2
          items2.push_back(items[i]);
        }
      }
      else {
        items2.push_back(items[i]);
      }
    }
    // milestone: aqui ja tenho uma solucao gerada
    // agora preciso fazer a busca local
    // tenta add os items não selecionados de antes e ver se gera uma mochila melhor
    for(auto& el: items2) {
      if(el.peso + peso <= W) {
        mochila.push_back(el);
        peso = peso + el.peso;
        valor = valor + el.valor;
      }
    }
    // milestone: encontramos (ou não) um vizinho melhor
    if(melhor_valor < valor) {
      melhor_valor = valor;
      melhor_mochila = mochila;
    }
  }
  // quero exibir a melhor mochila
  peso = 0;
  valor = 0;
  for (auto& el: melhor_mochila) {
    peso += el.peso;
    valor += el.valor;
  }
  cout << peso << " " << valor << " 0" << endl;
  sort(melhor_mochila.begin(), melhor_mochila.end(), [](auto& i, auto& j){return i.id < j.id;});
  for(auto& el: melhor_mochila) {
    cout << el.id << " ";
  }

  return 0;
}