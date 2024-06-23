#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um novo nó no final da lista
void append(Node** head_ref, char new_data) {
    Node* newNode = createNode(new_data);
    Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Função para imprimir a lista e os endereços
void printList(Node* node) {
    while (node != NULL) {
        printf("Caractere: %c, Endereço do elemento: %p, Endereço do próximo: %p\n", 
                node->data, (void*)node, (void*)node->next);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    char ch;
    
    // Leitura de 10 caracteres do usuário
    printf("Digite 10 caracteres:\n");
    for (int i = 0; i < 10; i++) {
        printf("Caractere %d: ", i + 1);
        scanf(" %c", &ch);
        append(&head, ch);
    }
    
    // Impressão da lista e dos endereços
    printf("\nLista de caracteres e seus endereços:\n");
    printList(head);

    return 0;
}
