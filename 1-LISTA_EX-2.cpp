#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int tamanho = 5; // Tamanho do vetor
    vector<int> vetorX(tamanho); // Vetor X
    vector<int> vetorY(tamanho); // Vetor Y

    // Lendo os elementos do vetor X
    cout << "Digite os " << tamanho << " elementos do vetor X:" << endl;
    for (int i = 0; i < tamanho; ++i) {
        cin >> vetorX[i];
    }

    // Calculando os elementos do vetor Y
    for (int i = 0; i < tamanho; ++i) {
        vetorY[i] = vetorX[i] * i;
    }

    // Imprimindo o vetor Y
    cout << "Vetor Y (elementos de X multiplicados pelos seus índices):" << endl;
    for (int i = 0; i < tamanho; ++i) {
        cout << vetorY[i] << " ";
    }
    cout << endl;

    return 0;
}
