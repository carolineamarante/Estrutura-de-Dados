#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int bbr(int v[], int baixo, int alto, int chave) {
    if (baixo > alto) {
        return -1;
    }
    
    int meio = (baixo + alto) / 2;
    
    if (v[meio] == chave) {
        return meio;
    }
    
    if (v[meio] < chave) {
        return bbr(v, meio + 1, alto, chave);
    } else {
        return bbr(v, baixo, meio - 1, chave);
    }
}

int main() {
    const int size = 50; 
    int v[size];
    
    srand(time(nullptr));
    
    for (int i = 0; i < size; i++) {
        v[i] = rand() % 101;
    }
    
    sort(v, v + size);
    
    cout << "Vetor ordenado: ";
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    int chave;
    cout << "Digite um valor para realizar a busca binária recursiva: ";
    cin >> chave;
    
    int resultado = bbr(v, 0, size - 1, chave);
    
    if (resultado != -1) {
        cout << "O valor " << chave << " foi encontrado no índice " << resultado << endl;
    } else {
        cout << "O valor " << chave << " não foi encontrado no vetor." << endl;
    }
    
    return 0;
}
