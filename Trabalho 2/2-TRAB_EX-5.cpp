#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista duplamente encadeada
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar um nó ao final da lista
void append(Node** head_ref, int new_data) {
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
    newNode->prev = last;
}

// Função para imprimir a lista
void printList(Node* node) {
    Node* last;
    printf("Lista em ordem: ");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\n");
}

// Função para buscar um item na lista
Node* search(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    Node* head = NULL;

    // Adicionando 20 itens inteiros à lista
    for (int i = 1; i <= 20; i++) {
        append(&head, i);
    }

    // Imprimindo a lista
    printList(head);

    // Testando a função de busca
    int key;
    printf("Digite um valor para buscar na lista: ");
    scanf("%d", &key);
    Node* result = search(head, key);
    if (result != NULL) {
        printf("Item %d encontrado no endereço %p\n", result->data, (void*)result);
    } else {
        printf("Item %d não encontrado na lista\n", key);
    }

    return 0;
}
