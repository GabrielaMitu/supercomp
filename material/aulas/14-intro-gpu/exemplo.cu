#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>
using namespace std;

int main(){
    thrust::host_vector<double> host(5,0); // cria host_vector na CPU
    host[4] = 35;
    thrust::device_vector<double> dev(host); // move os dados para a GPU
    host[2] = 12; // o vector que foi na GPU não foi alterado, só mudou na CPU
    printf("Host vector");
    for (auto i = host.begin(); i != host.end(); i++)
    {
        cout << *i << " ";
    }
    printf("\n");
    for(auto i = dev.begin(); i != dev.end(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}
