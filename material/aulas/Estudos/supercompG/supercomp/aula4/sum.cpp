#include<iostream>
#include<algorithm>
using namespace std;

constexpr int M = 2048;
constexpr int N = 2048;

double naive_sum(const double a[][N]){
    double sum = 0.0;
    for(int j = 0; j < N; ++j) {
        for(int i = 0; i < M; ++i)
            sum += a[i][j];
    }
    return sum;
}

double improved_sum(const double a[][N]) {
    double sum = 0.0;
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < N; ++j)
            sum +=a[i][j];
    return sum;
}

int main() {
    static double a[M][N];
    fill_n(&a[0][0], M*N, 1.0 / (M*N));
    cout << naive_sum(a) << endl;
    static double b[M][N];
    fill_n(&b[0][0], M*N, 1.0 / (M*N));
    cout << improved_sum(b) << endl;
    return 0;
}


// g++ -Wall -O3 -g sum.cpp -o sum
// valgrind --tool=callgrind ./sum
    // numeros = pids  --> vai criar arquivo callgrind.out.pid
    // refs = numero de leituras ram
// callgrind_annotate callgrind.out.61478 sum.cpp 
    // mostra o número de acessos ram por linha (dentro de um bloco pode se confundir - trocar linhas)