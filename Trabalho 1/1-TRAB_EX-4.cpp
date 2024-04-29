#include <iostream>

using namespace std;

int recursiveSum(int a, int b) {
    if (a == b) {
        return a;
    }
    return a + recursiveSum(a + 1, b);
}

int main () {
    int a,b;
    cout << "Inisira o valor de A: " << endl;
    cin >> a;
    cout << "Inisira o valor de B: " << endl;
    cin >> b;

    if (a < b) {
        int soma = recursiveSum(a, b);
        cout << "Soma = " << soma << endl;
    } else {
        cout << "Operação inválida. Insira um valor onde B seja maior que a A." << endl;
    }
}