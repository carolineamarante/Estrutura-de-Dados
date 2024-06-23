#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    float items[MAX];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, float value) {
    if (!isFull(s)) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack is full!\n");
    }
}

float pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack is empty!\n");
        return -1;
    }
}

float peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    } else {
        printf("Stack is empty!\n");
        return -1;
    }
}

int size(Stack *s) {
    return s->top + 1;
}

void displayMenu() {
    printf("PROGRAMA PILHA\n");
    printf("0: Sair\n");
    printf("1: Inserir itens\n");
    printf("2: Remover itens\n");
    printf("3: Imprimir Tamanho\n");
    printf("4: Imprimir Item Topo\n");
    printf("Entre com a opcao desejada: ");
}

int main() {
    Stack stack;
    int choice;
    float value;

    initialize(&stack);

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Saindo...\n");
                break;
            case 1:
                if (!isFull(&stack)) {
                    printf("Digite um valor float para inserir: ");
                    scanf("%f", &value);
                    push(&stack, value);
                } else {
                    printf("A pilha esta cheia!\n");
                }
                break;
            case 2:
                if (!isEmpty(&stack)) {
                    value = pop(&stack);
                    printf("Item removido: %f\n", value);
                } else {
                    printf("A pilha esta vazia!\n");
                }
                break;
            case 3:
                printf("Tamanho da pilha: %d\n", size(&stack));
                break;
            case 4:
                if (!isEmpty(&stack)) {
                    value = peek(&stack);
                    printf("Item no topo: %f\n", value);
                } else {
                    printf("A pilha esta vazia!\n");
                }
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (choice != 0);

    return 0;
}
