#include <iostream>
#include <vector>

using namespace std;

int main () {
    const int vectorSize = 20;
    int inputUsuario;
    vector<int> vetorBase(vectorSize);
    vector<int> numeroPar, numeroImpar;

    cout << "Digite 20 numeros diversos e inteiros: ";

    for (int i = 0; i < vectorSize; ++i) {
        cin >> inputUsuario; 
        vetorBase[i] = inputUsuario;
    }

    for (int i = 0; i < vectorSize; ++i) {
        if (vetorBase[i] % 2 == 0) {
            numeroPar.push_back(vetorBase[i]);
        } else {
            numeroImpar.push_back(vetorBase[i]);
        }
    }

    cout << numeroImpar.size() << endl;
    cout << "Numeros impares do vetor: ";
    for (int i = 0; i < numeroImpar.size(); ++i) {
        cout << numeroImpar[i] << " ";
    }
    cout << endl;

    cout << "Numeros pares do vetor: ";
    for (int i = 0; i < numeroPar.size(); ++i) {
        cout << numeroPar[i] << " ";
    }
    cout << endl;
}