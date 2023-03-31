#include <iostream>
#include <omp.h>
#include <cmath>

using namespace std;

int main() {
    int N=1000000000;


    double result = 1.0;
    for (int n=1; n< N; n+=1){
        result+=(pow(-1,n))/(2*n+1);
    }
    result*=4;

    cout << "Resultado: " << result<< endl;

//    #pragma omp parallel master  //thread de num 0  
//    {
       
//        nthreads = omp_get_num_threads();
//        cout << "Número de Threads: " << nthreads << endl;
//    }

//    #pragma omp parallel for
//        for(idx=0; idx<N; idx++){
//            a[idx]=b[idx]=1.0;
//        }
   

//    #pragma omp parallel for private(tid)
//        for(idx=0; idx<N; idx++){
//            c[idx]=a[idx]+b[idx];
//            tid = omp_get_thread_num();
//            cout << "Thread " << tid << ", c[" << idx << "] =" << c[idx] << endl;
//        }
   


   return 0;
}
// g++ -Wall -O3 calculoPI.cpp -o calculoPI

////////////////////////////////////////////////////////////////////////
// No PI recursivo
// A master é o produtor e chama as outras tasks (consumidores)
// As outras tasks vao chamando outras tasks e vai formando uma arvore
// No final a master junta tudo

// se tirasse as tasks e só deixasse o master seria sequencial

// pra processos mais pesados/demorados deve usar uma task
// se tem alguém livre ele aloca lá

