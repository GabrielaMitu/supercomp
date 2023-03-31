#include <iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;

struct Job {
    int id;
    int weight;
};

struct Machine {
    int id;
    int weight;
    vector<bool> arr;
};

int main(){
    // PRIMEIROS INPUTS
    int n = 0; // numero de jobs
    int W = 0; // numero de maquinas
    cin >> n >> W;

    vector<Job> Jobs;
    Jobs.reserve(n);
    int w;
    // Criando os ids dos jobs e seus respectivos pesos
    for(int i = 0; i < n; i++){
        cin >> w;
        Jobs.push_back({i, w});
    }

    // Algorithm
    vector<Machine> machines;
    machines.reserve(W);
    for(int i = 0; i < W; i++){
        machines[i] = {i,0,{}}; // tempo de processamento: 0, {}: vetor vazio
        machines[i].arr.reserve(n);
        for(int j = 0; j < n; j++){
            machines[i].arr.push_back(false); //  A cada iteração do loop, um valor booleano "false" é adicionado ao final do vetor "arr". Isso é feito para marcar que a máquina ainda não processou nenhuma tarefa.
        }
    }
    
    int total_time = -1;

    // ORDEM DECRESCENTE DE PESO DOS JOBS
    sort(Jobs.begin(), Jobs.end(), [](Job a, Job b){return a.weight > b.weight;}); 

    // Atribuir primeiro os trabalhos mais pesados às máquinas menos ocupadas
    for (auto& j : Jobs){
        int lowest = 8191; // big integer -> valor máximo representável em um byte (8 bits) com todos os bits ligados (em binário, 11111111)
        int index = 0;
        for(int i = 0; i < W; i++) {
            if (machines[i].weight < lowest){
                lowest = machines[i].weight;
                index = i;
            }
        }
        // Dar o job j para a máquina mais ociosa 
        machines[index].weight += j.weight;
        machines[index].arr[j.id] = true; // deixa em 1 o id do job que será feito em tal maquina
        if (machines[index].weight > total_time){
            total_time = machines[index].weight;
        }
    }

    for(int i = 0; i < W; i++){
        cout << "Máquina " << i << ": ";
        for(int j = 0; j < n; j++){
            cout << machines[i].arr[j] << " ";
        }
        cout << endl;
    }
    cout << "Tempo total de execução será: " << total_time << endl;
    
    return 0;
}