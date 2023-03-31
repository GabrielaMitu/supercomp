#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    
    // LEITURA DA INSTÂNCIA
    int n; // quant de cidades
    cin >> n;
    int k; // quant de centros
    cin >> k;

    vector<vector<int>> distancias; // matriz de distâncias

    for(int i = 0; i < n; i ++){ // linhas
      vector<int> linha;
      for(int j = 0; j < n; j++){ // colunas
           int distancia;
           cin >> distancia;
           linha.push_back(distancia);
      }
      distancias.push_back(linha);
    }

    // ESTRATÉGIA GULOSA

    vector<int> centros; // índices dos centros de distribuição
    int centro=0; // centro atual

    for(int c=0;c < k;c++){
       cout << centro << " ";
       centros.push_back(centro);
       centro = max_element(distancias[centro].begin(), distancias[centro].end()) - distancias[centro].begin(); // Calcula o índice da cidade mais distante do centro atual.
    }

    cout << endl;

    // CÁLCULO DOS CENTROS DE CADA CIDADE
    for(int cidade=0;cidade<n;cidade++){
        int dmin=0; //distância mínima
        centro=0;
        for(int c=0;c<centros.size();c++)
           if (distancias[cidade][centros[c]]<=dmin){
              dmin=distancias[cidade][centros[c]];
              centro=centros[c];
           }
        cout << centro << " ";
    }
    cout << endl;
}