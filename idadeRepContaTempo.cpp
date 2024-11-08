#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;


//Gera números aleatórios de 1 a 100
int generateNumber(){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(1, 100);

    return dist(gen);
}

bool idadeRep(const vector<int>& Idade){
    int tam = Idade.size();
    int menor = 200;
    for(int i = 0; i<tam; i++){
        if (Idade[i]<menor){
        menor = Idade[i];
        }
    }

    for(int i = 0; i<tam; i++){
        if (Idade[i]==menor){
        return true;
        }
    }

    return false;
}

int main() {
    // Captura o tempo de início
    auto start = std::chrono::high_resolution_clock::now();

    vector<int> idades;

    for(int i=0; i<1000000; i++){
        idades.push_back(generateNumber());
    }

    if (idadeRep(idades)) {
        cout << "There are repeated minimum ages." << endl;
    } else {
        cout << "No repeated minimum ages." << endl;
    }


    // Captura o tempo de término
    auto end = std::chrono::high_resolution_clock::now();

    // Calcula a duração em milissegundos
    std::chrono::duration<double, std::milli> duration = end - start;

    // Exibe o tempo de execução
    std::cout << "O código levou " << duration.count() << " milissegundos para rodar." << std::endl;

    return 0;
}