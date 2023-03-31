#include <iostream>
#include <cmath>
#include <iomanip>

// Versão feita por mim e Amandinha, usando pow para fazer potência


int main() {
  double S = 0;
  int n;
  std::cin >> n;
  for (int i = 0; i <= n; i++) {
    S += 1.0/pow(2,i);
  }
  std::cout << std::fixed << std::setprecision(15) << S;
  return 0;
}