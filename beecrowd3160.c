#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FRIENDS 1000
#define MAX_LENGTH 21

void add_friends(char **list, int *count, char *new_friends[], int new_count, int pos) {
    for (int i = 0; i < new_count; i++) {
        for (int j = *count; j > pos; j--) {
            list[j] = list[j - 1];
        }
        list[pos++] = new_friends[i];
        (*count)++;
    }
}

int main() {
    char line[MAX_FRIENDS * MAX_LENGTH];
    char *current_friends[MAX_FRIENDS];
    char *new_friends[MAX_FRIENDS];
    int current_count = 0, new_count = 0;

    // Ler a lista atual de amigos
    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " \n");
    while (token != NULL) {
        current_friends[current_count++] = strdup(token);
        token = strtok(NULL, " \n");
    }

    // Ler a nova lista de amigos
    fgets(line, sizeof(line), stdin);
    token = strtok(line, " \n");
    while (token != NULL) {
        new_friends[new_count++] = strdup(token);
        token = strtok(NULL, " \n");
    }

    // Ler o nome do amigo que receberá a nova lista
    fgets(line, sizeof(line), stdin);
    strtok(line, "\n"); // Remover o newline do final

    // Adicionar novos amigos à lista atual
    if (strcmp(line, "nao") == 0) {
        // Adicionar ao final
        for (int i = 0; i < new_count; i++) {
            current_friends[current_count++] = new_friends[i];
        }
    } else {
        // Procurar o amigo para inserção
        int pos = 0;
        for (pos = 0; pos < current_count; pos++) {
            if (strcmp(current_friends[pos], line) == 0) {
                break;
            }
        }
        add_friends(current_friends, &current_count, new_friends, new_count, pos);
    }

    // Imprimir a lista atualizada
    for (int i = 0; i < current_count; i++) {
        printf("%s", current_friends[i]);
        if (i < current_count - 1) {
            printf(" ");
        }
    }
    printf("\n");

    // Liberar memória alocada
    for (int i = 0; i < current_count; i++) {
        free(current_friends[i]);
    }

    return 0;
}
