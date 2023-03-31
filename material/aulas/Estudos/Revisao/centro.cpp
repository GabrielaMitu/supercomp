
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    
    // LEITURA DA INSTÂNCIA
    int n;
    std::cin >> n;
    int k;
    std::cin >> k;

    std::vector<std::vector<int>> distancias; // matriz de distâncias

    for(int i = 0; i < n; i ++){
      std::vector<int> linha;
      for(int j = 0; j < n; j++){
           int distancia;
           std::cin >> distancia;
           linha.push_back(distancia);
      }
      distancias.push_back(linha);
    }

    // ESTRATÉGIA GULOSA

    std::vector<int> centros; // índices dos centros de distribuição
    int centro=0; // centro atual

    for(int c=0;c<k;c++){
       std::cout<<centro<<" ";
       centros.push_back(centro);
       centro=std::max_element(distancias[centro].begin(),distancias[centro].end()) 
              - distancias[centro].begin();
    }

    std::cout<<std::endl;

    // CÁLCULO DOS CENTROS DE CADA CIDADE

    for(int cidade=0;cidade<n;cidade++){
        int dmin=0; //distância mínima
        centro=0;
        for(int c=0;c<centros.size();c++)
           if (distancias[cidade][centros[c]]<=dmin){
              dmin=distancias[cidade][centros[c]];
              centro=centros[c];
           }
        std::cout<<centro<<" ";
    }
    std::cout<<std::endl;
}
