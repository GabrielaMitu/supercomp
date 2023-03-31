#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int a=0;
   #pragma omp parallel
   {
       #pragma omp critical
       a=a+ omp_get_thread_num();
   }
   cout << a << endl;
   return 0;
}

// g++ -Wall -O3 -fopenmp exemplo1.cpp -o exemplo1


// Sem o semáforo:
// a fica em race condition (disputa entre threads)
// cada vez sai um output de a diferente

// #pragma omp critical --> define como regiao critica (faz semaforos) e faz o a ficar global
// Com isso, sempre sai o mesmo output


// -----------------------------------------------------
#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int iam;
   #pragma omp parallel private(iam)  // privada garante que threads nao se falam entre si
   {
       iam = omp_get_thread_num();  // todas as threads enxergam a iam
       #pragma omp critical  // Se nao botar como critical, a variável pode ficar confusa e pegar lixo de mem
       cout << "Olá, eu sou a thread num " << iam << endl;

   }
   return 0;
}


// Openmp cria varias threads mas a mais rapida que vai ser alocada antes
// quando vc da critical, ele executa tudo certinho

//----------------------------------------------------------------
#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int iam;
   #pragma omp parallel private(iam)  
   {
       
       iam = omp_get_thread_num();  
       #pragma omp single  // Só printa a thread q executou mais rápido
       cout << "Olá, eu sou a thread num " << iam << endl;

   }
   return 0;
}

// -----------------------------------------------------------
#include <iostream>

using namespace std;

int main() {
   #pragma omp parallel
   {
       cout << "Hello World" << endl;
   }
   return 0;
}

// g++ -Wall -O3 -fopenmp exemplo1.cpp -o exemplo1

// --------------------------------------------------------------]
#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int N=100;
    int nthreads, tid, idx;
    float a[N], b[N], c[N];


   #pragma omp parallel master  //thread de num 0  
   {
       
       nthreads = omp_get_num_threads();
       cout << "Número de Threads: " << nthreads << endl;
   }

   #pragma omp parallel for
       for(idx=0; idx<N; idx++){
           a[idx]=b[idx]=1.0;
       }
   

   #pragma omp parallel for private(tid)
       for(idx=0; idx<N; idx++){
           c[idx]=a[idx]+b[idx];
           tid = omp_get_thread_num();
           cout << "Thread " << tid << ", c[" << idx << "] =" << c[idx] << endl;
       }
   


   return 0;
}
