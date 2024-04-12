#include <iostream>
#include <string>

using namespace std;

int main() {
    string nome, sobrenome, nomeCompleto;

    // Solicita ao usuário o nome
    cout << "Digite o nome: ";
    getline(cin, nome);

    // Solicita ao usuário o sobrenome
    cout << "Digite o sobrenome: ";
    getline(cin, sobrenome);

    // Junta o nome e sobrenome em uma única string
    nomeCompleto = nome + " " + sobrenome;

    // Informa a nova string, o número de caracteres, a primeira e a última letra
    cout << "Nova string: " << nomeCompleto << endl;
    cout << "Numero de caracteres: " << nomeCompleto.length() << endl;
    cout << "Primeira letra: " << nomeCompleto[0] << endl;
    cout << "Ultima letra: " << nomeCompleto[nomeCompleto.length() - 1] << endl;

    return 0;
}
