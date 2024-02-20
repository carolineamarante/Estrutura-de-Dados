#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


int random_number() {
    return rand() % 41 - 20;
}

int main() {
    srand(time(nullptr)); 


    vector<int> vetor1(10);
    for (int i = 0; i < 10; ++i) {
        vetor1[i] = random_number();
    }


    cout << "a. Paridade dos elementos do vetor:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Elemento " << vetor1[i] << " é ";
        if (vetor1[i] % 2 == 0) {
            cout << "par" << endl;
        } else {
            cout << "ímpar" << endl;
        }
    }


    int menor = vetor1[0], maior = vetor1[0];
    int pos_menor = 0, pos_maior = 0;
    for (int i = 1; i < 10; ++i) {
        if (vetor1[i] < menor) {
            menor = vetor1[i];
            pos_menor = i;
        }
        if (vetor1[i] > maior) {
            maior = vetor1[i];
            pos_maior = i;
        }
    }
    cout << "b. Menor elemento do vetor é " << menor << " na posição " << pos_menor << endl;
    cout << "   Maior elemento do vetor é " << maior << " na posição " << pos_maior << endl;


    int soma = 0;
    for (int i = 0; i < 10; ++i) {
        soma += vetor1[i];
    }
    cout << "c. Soma de todos os elementos do vetor: " << soma << endl;


    int soma_positivos = 0;
    for (int i = 0; i < 10; ++i) {
        if (vetor1[i] > 0) {
            soma_positivos += vetor1[i];
        }
    }
    cout << "d. Soma de todos os elementos positivos do vetor: " << soma_positivos << endl;


    int valor;
    cout << "Digite um valor para verificar se está no vetor: ";
    cin >> valor;
    bool encontrado = false;
    for (int i = 0; i < 10; ++i) {
        if (vetor1[i] == valor) {
            cout << "O valor " << valor << " está no vetor na posição " << i << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "O valor " << valor << " não está no vetor." << endl;
    }


    vector<int> vetor2(10);
    cout << "Elementos que aparecem em ambos os vetores:" << endl;
    for (int i = 0; i < 10; ++i) {
        vetor2[i] = random_number();
        cout << "Vetor1[" << i << "] = " << vetor1[i] << ", Vetor2[" << i << "] = " << vetor2[i] << endl;
        if (find(vetor1.begin(), vetor1.end(), vetor2[i]) != vetor1.end()) {
            cout << "  O elemento " << vetor2[i] << " aparece nos dois vetores." << endl;
        }
    }

    return 0;
}
