#include <iostream>
#include <vector>

using namespace std;

class vetorNumerosInteiros {
private:
    vector<int> vetor;

public:
    vetorNumerosInteiros(int tamanho) : vetor(tamanho) {}

    void getValores() {
        cout << "Digite os valores do vetor: \n";
        for (int i = 0; i < vetor.size(); i++) {
            cout << "Valor " << i + 1 << ": ";
            cin >> vetor[i];
        }
    }

    void doubleValores() {
        for (int i = 0; i < vetor.size(); i++) {
            vetor[i] *= 2;
        }
    }

    void showValores() const {
        cout << "Valores dentro do vetor: \n";
        for (int i = 0; i < vetor.size(); i++) {
            cout << vetor[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int tamanhoVetor;

    cout << "Informe a quantidade de itens do vetor: ";
    cin >> tamanhoVetor;

    vetorNumerosInteiros vetorUsuario(tamanhoVetor);

    vetorUsuario.getValores();
    vetorUsuario.doubleValores();
    vetorUsuario.showValores();

    return 0;
}
