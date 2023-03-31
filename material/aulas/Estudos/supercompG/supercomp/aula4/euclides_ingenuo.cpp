
#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<std::vector<double>> matriz;

void calcula_distancias(matriz &mat, std::vector<double> &x, std::vector<double> &y) {
    int n = x.size();
    for (int i = 0; i < n; i++) {
        std::vector<double> linha;
        for (int j = 0; j < n; j++) {
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            linha.push_back((dx*dx + dy*dy));    
        }
        mat.push_back(linha);
    }
}


int main() {
    matriz mat;
    std::vector<double> x, y;
    int n;

    std::cin >> n;
    x.reserve(n);
    y.reserve(n);
    for (int i = 0; i < n; i++) {
        double xt, yt;
        std::cin >> xt >> yt;
        x.push_back(xt);
        y.push_back(yt);
    }

    calcula_distancias(mat, x, y);
    

    for (auto &linha : mat) {
        for (double el : linha) {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }

    return 0;
}



// g++ -Wall -O3 -g euclides-ingenuo.cpp -o euclides-ingenuo < 6-in-0.txt 
// valgrind --tool=callgrind ./euclides-ingenuo < 6-in-0.txt 
// callgrind_annotate callgrind.out.63031 euclides-ingenuo.cpp 