#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n_alunos;
    cout << "Insira o número de alunos: ";
    cin >> n_alunos;

    vector<int> notas(n_alunos);
    vector<int> histograma(5, 0);

    for (int i = 0; i < n_alunos; i++) {
        cout << "Insira a nota " << i+1 << ": ";
        cin >> notas[i];

        int indice = (notas[i] >= 9) ? 0 :
                     (notas[i] >= 7) ? 1 :
                     (notas[i] >= 5) ? 2 :
                     (notas[i] >= 3) ? 3 : 4;
        histograma[indice]++;
    }

    char conceitos[5] = {'A', 'B', 'C', 'D', 'E'};
    for (int i = 0; i < 5; i++) {
        cout << conceitos[i] << ": ";
        for (int j = 0; j < histograma[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
