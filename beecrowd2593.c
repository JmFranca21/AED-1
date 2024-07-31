#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 10000
#define MAX_WORDS 128
#define MAX_WORD_LENGTH 50

void find_word_positions(char *text, char *word) {
    int text_length = strlen(text);
    int word_length = strlen(word);
    int found = 0;

    for (int i = 0; i <= text_length - word_length; i++) {
        // Verifica se a palavra começa na posição i
        if (strncmp(&text[i], word, word_length) == 0) {
            // Verifica se a palavra encontrada é exata (não é subpalavra)
            if ((i == 0 || text[i - 1] == ' ') && (text[i + word_length] == ' ' || text[i + word_length] == '\0')) {
                if (found) {
                    printf(" ");
                }
                printf("%d", i);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("-1");
    }
    printf("\n");
}

int main() {
    char text[MAX_TEXT_SIZE + 1];
    int n;
    char words[MAX_WORDS][MAX_WORD_LENGTH + 1];

    // Lê o texto
    fgets(text, sizeof(text), stdin);
    // Remove o newline do final do texto
    text[strcspn(text, "\n")] = 0;

    // Lê o número de palavras
    scanf("%d", &n);
    getchar(); // Consome o newline após o número

    // Lê as palavras
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    // Para cada palavra, encontre suas posições no texto
    for (int i = 0; i < n; i++) {
        find_word_positions(text, words[i]);
    }

    return 0;
}
