#include <iostream>
#include <string>

using namespace std;

int main() {
    string entrada, inverso;

    // Solicita ao usuário uma string
    cout << "Digite uma string: ";
    getline(cin, entrada);

    // Inverte a string
    for (int i = entrada.length() - 1; i >= 0; --i) { //--i faz  for ao contrario, precisa do -1 porque o length nao comeca no indice 0, mas o array sim, que e o que o for leva em consideracao
        inverso += entrada[i]; // += soma o valor como se fosse inverso + entrada
    }

    // Exibe o inverso da string
    cout << "Inverso da string: " << inverso << endl;

    return 0;
}
