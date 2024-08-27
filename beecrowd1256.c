#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar cada "bucket" da tabela de dispersão
struct Node {
    int data;
    struct Node *next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir uma chave na tabela de dispersão
void insert(struct Node* hashTable[], int index, int key) {
    struct Node *newNode = createNode(key);
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node *temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Função para imprimir a tabela de dispersão
void printHashTable(struct Node* hashTable[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ->", i);
        struct Node *temp = hashTable[i];
        while (temp != NULL) {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" \\\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);  // Número de casos de teste

    while (N--) {
        int M, C;
        scanf("%d %d", &M, &C);  // M: tamanho da tabela, C: número de chaves

        // Inicializa a tabela de dispersão com NULLs
        struct Node* hashTable[M];
        for (int i = 0; i < M; i++) {
            hashTable[i] = NULL;
        }

        // Lê e insere cada chave na tabela de dispersão
        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            int index = key % M;
            insert(hashTable, index, key);
        }

        // Imprime a tabela de dispersão
        printHashTable(hashTable, M);

        if (N) {
            printf("\n");  // Linha em branco entre casos de teste
        }

        // Libera a memória usada pela tabela de dispersão
        for (int i = 0; i < M; i++) {
            struct Node *temp = hashTable[i];
            while (temp != NULL) {
                struct Node *toFree = temp;
                temp = temp->next;
                free(toFree);
            }
        }
    }

    return 0;
}
