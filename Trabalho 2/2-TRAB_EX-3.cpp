#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int front, rear;
} Queue;

void initialize(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, char value) {
    if (!isFull(q)) {
        q->items[++(q->rear)] = value;
    } else {
        printf("Queue is full!\n");
    }
}

char dequeue(Queue *q) {
    if (!isEmpty(q)) {
        return q->items[(q->front)++];
    } else {
        printf("Queue is empty!\n");
        return '\0';
    }
}

void readCharacters(Queue *upperQueue, Queue *lowerQueue) {
    char ch;
    printf("Digite caracteres (pressione ENTER para terminar): ");
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                enqueue(upperQueue, ch);
            } else if (islower(ch)) {
                enqueue(lowerQueue, ch);
            }
        }
    }
}

void printQueue(Queue *q) {
    while (!isEmpty(q)) {
        printf("%c ", dequeue(q));
    }
    printf("\n");
}

int main() {
    Queue upperQueue, lowerQueue;

    initialize(&upperQueue);
    initialize(&lowerQueue);

    readCharacters(&upperQueue, &lowerQueue);

    printf("Conteúdo da fila de letras maiúsculas: ");
    printQueue(&upperQueue);

    printf("Conteúdo da fila de letras minúsculas: ");
    printQueue(&lowerQueue);

    return 0;
}
