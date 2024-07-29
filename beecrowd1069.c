#include <stdio.h>
#include <string.h>

// Função para contar diamantes em uma string
int count_diamonds(char *str) {
    int count = 0;
    int stack = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '<') {
            stack++;
        } else if (str[i] == '>' && stack > 0) {
            count++;
            stack--;
        }
    }

    return count;
}

int main() {
    int N;
    char str[1001];

    // Lê o número de casos de teste
    scanf("%d", &N);
    getchar(); // Consumir o caractere de nova linha após o número

    for (int i = 0; i < N; i++) {
        // Lê cada linha de entrada
        fgets(str, sizeof(str), stdin);
        // Remove o caractere de nova linha no final da string, se presente
        str[strcspn(str, "\n")] = '\0';

        // Conta e imprime o número de diamantes possíveis de serem extraídos
        printf("%d\n", count_diamonds(str));
    }

    return 0;
}
