#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>

int main() {
    thrust::host_vector<string> host;

    string n;
    while (n != ""){
        cin >> n;
        host.push_back(n);
    }
    
    for (auto &el : host){
        cout << el;
    }
    
}


// nvcc -arch=sm_70 -std=c++14 exercicio.cu -o exercicio

 