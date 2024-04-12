#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int arraySize = 20; // arraySize do vetor
    vector<int> vetorX(arraySize); // Vetor X
    vector<int> vetorY; // Vetor Y para números pares
    vector<int> vetorZ; // Vetor Z para números ímpares

    srand(time(nullptr)); // Inicializando a semente para geração de números aleatórios

    // Preenchendo o vetor X com números aleatórios no intervalo [-20, 20]
    for (int i = 0; i < arraySize; ++i) {
        vetorX[i] = rand() % 41 - 20;
        cout << vetorX[i] << endl;
    }

    // Separando os elementos pares e ímpares de X nos vetores Y e Z, respectivamente
    for (int i = 0; i < arraySize; ++i) {
        if (vetorX[i] % 2 == 0) {
            vetorY.push_back(vetorX[i]); // Adiciona o elemento par ao vetor Y
        } else {
            vetorZ.push_back(vetorX[i]); // Adiciona o elemento ímpar ao vetor Z
        }
    }

    // Imprimindo os vetores Y e Z
    cout << vetorY.size() << endl;    
    cout << "Vetor Y (pares): ";
    for (int i = 0; i < vetorY.size(); ++i) {
        cout << vetorY[i] << " ";
    }
    cout << endl;
 
    cout << "Vetor Z (ímpares): ";
    for (int i = 0; i < vetorZ.size(); ++i) { //size e utilizado para numeros e o length string
        cout << vetorZ[i] << " ";
    }
    cout << endl;

    return 0;
}
