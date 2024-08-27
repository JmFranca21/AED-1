#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 201

// Função para converter uma string para minúsculas
void to_lowercase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);  // Função de <ctype.h>, parte do ANSI C
        str++;
    }
}

// Função para comparar duas strings (usada na ordenação)
int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);  // Função de <string.h>, parte do ANSI C
}

int main() {
    char *words[MAX_WORDS]; // Array para armazenar as palavras únicas
    int word_count = 0;
    char word[MAX_WORD_LENGTH];
    int i;
    
    // Inicializa a lista de palavras
    for (i = 0; i < MAX_WORDS; i++) {
        words[i] = NULL;
    }

    // Leitura das palavras
    while (scanf("%200[a-zA-Z]", word) != EOF) {  // scanf é parte de <stdio.h>, padrão ANSI C
        // Converte a palavra para minúsculas
        to_lowercase(word);

        // Verifica se a palavra já existe na lista
        int found = 0;
        for (i = 0; i < word_count; i++) {
            if (strcmp(words[i], word) == 0) {  // strcmp é parte de <string.h>
                found = 1;
                break;
            }
        }

        // Se não encontrou, adiciona a palavra à lista
        if (!found) {
            words[word_count] = (char *)malloc(strlen(word) + 1);  // malloc e strlen são de <stdlib.h> e <string.h>, respectivamente
            strcpy(words[word_count], word);  // strcpy é parte de <string.h>
            word_count++;
        }

        // Ignora os caracteres que não são letras
        scanf("%*[^a-zA-Z]");
    }

    // Ordena as palavras em ordem alfabética
    qsort(words, word_count, sizeof(char *), compare_strings);  // qsort é de <stdlib.h>

    // Imprime as palavras
    for (i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);  // printf é parte de <stdio.h>
        free(words[i]); // Libera a memória alocada para cada palavra, free é parte de <stdlib.h>
    }

    return 0;
}
