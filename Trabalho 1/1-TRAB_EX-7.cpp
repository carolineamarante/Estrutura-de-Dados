#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_FUNCIONARIOS = 100;
const int MAX_DEPARTAMENTOS = 8;

// Estrutura para armazenar as informações de um funcionário
struct Funcionario {
    string nome;
    int idade;
    char sexo;
    int tempoDeCasa;
    float salario;
};

int main() {
    vector<Funcionario> funcionarios(MAX_FUNCIONARIOS);
    int numFuncionarios;

    // Leitura do número de funcionários e suas informações
    cout << "Digite o número de funcionários: ";
    cin >> numFuncionarios;

    for (int i = 0; i < numFuncionarios; i++) {
        cout << "\nInformações do funcionário " << i + 1 << ":\n";
        cout << "Nome: ";
        cin >> funcionarios[i].nome;
        cout << "Idade: ";
        cin >> funcionarios[i].idade;
        cout << "Sexo (M/F): ";
        cin >> funcionarios[i].sexo;
        cout << "Tempo de casa (anos): ";
        cin >> funcionarios[i].tempoDeCasa;
        cout << "Salário (R$): ";
        cin >> funcionarios[i].salario;
    }

    // a) Procurar funcionário pelo nome
    string nomeProcurado;
    cout << "\nDigite o nome do funcionário a ser procurado: ";
    cin >> nomeProcurado;

    cout << "\nFuncionários com o nome " << nomeProcurado << ":\n";
    for (int i = 0; i < numFuncionarios; i++) {
        if (funcionarios[i].nome == nomeProcurado) {
            cout << "Nome: " << funcionarios[i].nome << endl;
            cout << "Idade: " << funcionarios[i].idade << endl;
            cout << "Sexo: " << funcionarios[i].sexo << endl;
            cout << "Tempo de Casa: " << funcionarios[i].tempoDeCasa << " anos" << endl;
            cout << "Salário: R$ " << funcionarios[i].salario << endl;
        }
    }

    // b) Número de funcionários de um departamento
    int departamentoDesejado;
    cout << "\nDigite o número do departamento desejado (1 a 8): ";
    cin >> departamentoDesejado;

    int contadorDepartamento = 0;
    for (int i = 0; i < numFuncionarios; i++) {
        // Supondo que cada funcionário tem um departamento associado (1 a 8)
        if (i % MAX_DEPARTAMENTOS + 1 == departamentoDesejado) {
            contadorDepartamento++;
        }
    }
    cout << "Número de funcionários no departamento " << departamentoDesejado << ": " << contadorDepartamento << endl;

    // c) Número de funcionárias do sexo feminino
    int contadorFeminino = 0;
    for (int i = 0; i < numFuncionarios; i++) {
        if (funcionarios[i].sexo == 'F' || funcionarios[i].sexo == 'f') {
            contadorFeminino++;
        }
    }
    cout << "Número de funcionárias do sexo feminino: " << contadorFeminino << endl;

    // d) Funcionários com o menor e maior tempo de casa
    int indiceMenorTempo = 0;
    int indiceMaiorTempo = 0;

    for (int i = 1; i < numFuncionarios; i++) {
        if (funcionarios[i].tempoDeCasa < funcionarios[indiceMenorTempo].tempoDeCasa) {
            indiceMenorTempo = i;
        }
        if (funcionarios[i].tempoDeCasa > funcionarios[indiceMaiorTempo].tempoDeCasa) {
            indiceMaiorTempo = i;
        }
    }

    cout << "\nFuncionário com o menor tempo de casa:\n";
    cout << "Nome: " << funcionarios[indiceMenorTempo].nome << endl;
    cout << "Tempo de Casa: " << funcionarios[indiceMenorTempo].tempoDeCasa << " anos" << endl;

    cout << "\nFuncionário com o maior tempo de casa:\n";
    cout << "Nome: " << funcionarios[indiceMaiorTempo].nome << endl;
    cout << "Tempo de Casa: " << funcionarios[indiceMaiorTempo].tempoDeCasa << " anos" << endl;

    // e) Salário médio por departamento
    vector<float> salariosDepartamento(MAX_DEPARTAMENTOS, 0.0);
    vector<int> contadoresDepartamento(MAX_DEPARTAMENTOS, 0);

    for (int i = 0; i < numFuncionarios; i++) {
        int departamento = i % MAX_DEPARTAMENTOS;
        salariosDepartamento[departamento] += funcionarios[i].salario;
        contadoresDepartamento[departamento]++;
    }
    cout << "\nSalário médio por departamento:\n";
    for (int i = 0; i < MAX_DEPARTAMENTOS; i++) {
        if (contadoresDepartamento[i] > 0) {
            cout << "Departamento " << i + 1 << ": R$ " << salariosDepartamento[i] / contadoresDepartamento[i] << endl;
        }
    }

    // f) Idade média por departamento
    vector<int> idadesDepartamento(MAX_DEPARTAMENTOS, 0);

    for (int i = 0; i < numFuncionarios; i++) {
        int departamento = i % MAX_DEPARTAMENTOS;
        idadesDepartamento[departamento] += funcionarios[i].idade;
    }

    cout << "\nIdade média por departamento:\n";
    for (int i = 0; i < MAX_DEPARTAMENTOS; i++) {
        if (contadoresDepartamento[i] > 0) {
            cout << "Departamento " << i + 1 << ": " << static_cast<float>(idadesDepartamento[i]) / contadoresDepartamento[i] << " anos" << endl;
        }
    }

    // g) Número de funcionários do sexo masculino e feminino, com idade entre 29 e 35 anos
    int contadorMasculinoIdade = 0;
    int contadorFemininoIdade = 0;

    for (int i = 0; i < numFuncionarios; i++) {
        if ((funcionarios[i].sexo == 'M' || funcionarios[i].sexo == 'm') && (funcionarios[i].idade >= 29 && funcionarios[i].idade <= 35)) {
            contadorMasculinoIdade++;
        } else if ((funcionarios[i].sexo == 'F' || funcionarios[i].sexo == 'f') && (funcionarios[i].idade >= 29 && funcionarios[i].idade <= 35)) {
            contadorFemininoIdade++;
        }
    }

    cout << "\nNúmero de funcionários do sexo masculino (29-35 anos): " << contadorMasculinoIdade << endl;
    cout << "Número de funcionários do sexo feminino (29-35 anos): " << contadorFemininoIdade << endl;

    return 0;
}
