#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 1000
#define MAX_LENGTH 21

// Função para comparar duas strings para ordenação alfabética
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N;
    scanf("%d\n", &N);  // Lê o número de listas de compras

    for (int i = 0; i < N; ++i) {
        char line[MAX_ITEMS * MAX_LENGTH];
        fgets(line, sizeof(line), stdin);  // Lê a lista de compras

        // Separar itens da lista
        char *items[MAX_ITEMS];
        int item_count = 0;
        char *token = strtok(line, " \n");
        
        while (token != NULL) {
            items[item_count++] = token;
            token = strtok(NULL, " \n");
        }

        // Ordenar os itens
        qsort(items, item_count, sizeof(char *), compare);

        // Remover itens duplicados e imprimir a lista ordenada sem duplicados
        printf("%s", items[0]);
        for (int j = 1; j < item_count; ++j) {
            if (strcmp(items[j], items[j - 1]) != 0) {
                printf(" %s", items[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
