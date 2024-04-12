#include <stdio.h>
#include <stdbool.h>

#define MAX_LANCAMENTOS 100 //def e um pre processador, que roda antes do codigo compilar de fato, tipo def PI 3,14 entao toda vez que PI for mencionado troca por 3,14

// Função para verificar se uma sequência de lançamentos é válida
bool sequenciaValida(int lancamentos[], int n) {
    printf("numero de lancamento max do user : %d\n", n);
    bool duplicataEncontrada = false;
    for (int i = 0; i < n; i++) {
        printf("%d == %d\n", lancamentos[i], lancamentos[i - 1]);
        printf("%d == %d\n", i, i - 1);
        if (lancamentos[i] == lancamentos[i - 1]) {
            printf("numero duplicado encontrado\n");
            duplicataEncontrada = true;
            if (duplicataEncontrada) {
                return false; // Sequência inválida
            }
        } else {
            printf("numero duplicado nao encontrado\n");
        }
    }
    return true; // Sequência válida
}

int main() {
    int n; //numero de lancamentos, quantia de numeros que o usuario vai colocar tipo 1 2 3 4 5, esses pertencem ao LANCAMENTOS (array)
    int lancamentos[MAX_LANCAMENTOS]; //a declaracao da quantia de itens do array ajuda no gerenciamento de memoria, entao quando for declarado precisa colocar o []

    // Solicita o número de lançamentos ao usuário
    printf("Digite o numero de lancamentos: ");
    scanf("%d", &n);

    // Verifica se o número de lançamentos é válido
    if (n < 1 || n > MAX_LANCAMENTOS) {
        printf("Numero de lancamentos invalido.\n");
        return 1;
    }

    // Solicita os lançamentos ao usuário e armazena no vetor
    printf("Digite os lancamentos:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &lancamentos[i]);
    }

    // Verifica se a sequência de lançamentos é válida
    if (sequenciaValida(lancamentos, n)) {
        printf("Sequencia de lancamentos valida.\n");
    } else {
        printf("Sequencia de lancamentos nao valida.\n");
    }

    return 0;
}
