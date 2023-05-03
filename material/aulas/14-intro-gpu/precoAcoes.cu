#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <thrust/device_vector.h>
#include <thrust/reduce.h>

int main() {
    // Lê os dados do arquivo
    std::ifstream input("stocks-google.txt");
    int n;
    input >> n;

    thrust::device_vector<double> d_vec(n);
    std::istream_iterator<double> iter(input);
    std::copy_n(iter, n, d_vec.begin());

    // Calcula o preço médio das ações nos últimos 10 anos
    double avg_all_years = thrust::reduce(d_vec.begin(), d_vec.end()) / n;

    // Calcula o preço médio das ações no último ano (365 dias atrás)
    int last_year_start = n - 365;
    double avg_last_year = thrust::reduce(d_vec.begin() + last_year_start, d_vec.end()) / 365;

    // Encontra o maior e o menor preço da sequência inteira e do último ano
    auto pair_all_years = thrust::minmax_element(d_vec.begin(), d_vec.end());
    double min_all_years = *pair_all_years.first;
    double max_all_years = *pair_all_years.second;
    auto pair_last_year = thrust::minmax_element(d_vec.begin() + last_year_start, d_vec.end());
    double min_last_year = *pair_last_year.first;
    double max_last_year = *pair_last_year.second;

    // Imprime os resultados
    std::cout << "Preço médio das ações nos últimos 10 anos: " << avg_all_years << std::endl;
    std::cout << "Preço médio das ações no último ano: " << avg_last_year << std::endl;
    std::cout << "Menor preço nos últimos 10 anos: " << min_all_years << std::endl;
    std::cout << "Maior preço nos últimos 10 anos: " << max_all_years << std::endl;
    std::cout << "Menor preço no último ano: " << min_last_year << std::endl;
    std::cout << "Maior preço no último ano: " << max_last_year << std::endl;

    return 0;
}
