#include <iostream>
#include <cmath>

using namespace std;

class equacaoSegundoGrau {
private:
    double a, b, c;

public:
    equacaoSegundoGrau (double a, double b, double c) : a(a), b(b), c(c) {}
    double calcularDelta() {
        return pow(b, 2) - 4 * a * c;
    }

    void exibirCoeficientes() {
        cout << "Coeficientes: a = " << a << ", b = " << b << ", c = " << c << endl;
    }
};

int main() {
    double a, b, c;

    cout << endl;
    cout << "Cálculo de equações do segundo grau em C++" << endl;
    cout << endl;
    cout << "Digite o coeficiente A: " << endl;
    cin >> a;
    cout << "Digite o coeficiente B: " << endl;
    cin >> b;
    cout << "Digite o coeficiente C: " << endl;
    cin >> c;

    equacaoSegundoGrau equacao(a, b, c);

    equacao.exibirCoeficientes();

    double delta = equacao.calcularDelta();
    cout << "Δ = " << delta << endl;

    return 0;
}
