#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);  // Lê o número de casos de teste

    while (N--) {
        int K;
        scanf("%d", &K);  // Lê o número de pessoas no grupo
        
        char idioma[101][21];  // Array para armazenar os idiomas
        int all_same = 1;  // Flag para verificar se todos os idiomas são iguais
        
        // Lê o primeiro idioma
        scanf("%s", idioma[0]);
        
        // Lê os idiomas das outras pessoas e compara com o primeiro
        for (int i = 1; i < K; i++) {
            scanf("%s", idioma[i]);
            if (strcmp(idioma[0], idioma[i]) != 0) {
                all_same = 0;  // Se houver um idioma diferente, define a flag como 0
            }
        }
        
        // Verifica a flag para decidir a saída
        if (all_same) {
            printf("%s\n", idioma[0]);  // Se todos forem iguais, imprime o idioma
        } else {
            printf("ingles\n");  // Caso contrário, imprime "ingles"
        }
    }

    return 0;
}
