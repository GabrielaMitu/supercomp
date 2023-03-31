#include <iostream>
#include <cmath>
#include <iomanip>

// Versão feita pelo professor com shift


int main() {
  double S = 1;
  int n, p=1;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    S += 1.0/(p=p<<1); //Coloca o p shiftado na variável p e pula o primeiro passo do cálculo. Logo a soma começa com S=1 e p=1
  }
  std::cout << std::fixed << std::setprecision(15) << S;
  return 0;
}