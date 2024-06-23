#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
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

void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack is full!\n");
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack is empty!\n");
        return -1;
    }
}

void readValues(Stack *evenStack, Stack *oddStack) {
    int value;
    for (int i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &value);
        if (value % 2 == 0) {
            push(evenStack, value);
        } else {
            push(oddStack, value);
        }
    }
}

void printStack(Stack *s) {
    while (!isEmpty(s)) {
        printf("%d ", pop(s));
    }
    printf("\n");
}

int main() {
    Stack evenStack, oddStack;

    initialize(&evenStack);
    initialize(&oddStack);

    readValues(&evenStack, &oddStack);

    printf("Valores pares desempilhados: ");
    printStack(&evenStack);

    printf("Valores impares desempilhados: ");
    printStack(&oddStack);

    return 0;
}
