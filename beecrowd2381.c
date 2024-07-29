#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de comparação para qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    char *nomes[N];
    char buffer[21];  // Buffer para armazenar os nomes temporariamente (máximo 20 caracteres + '\0')
    
    // Ler os nomes dos alunos
    for (int i = 0; i < N; i++) {
        scanf("%s", buffer);
        nomes[i] = strdup(buffer);
    }
    
    // Ordenar os nomes em ordem alfabética
    qsort(nomes, N, sizeof(char *), compare);
    
    // Imprimir o K-ésimo aluno (K-1 devido ao índice ser baseado em 0)
    printf("%s\n", nomes[K - 1]);
    
    // Liberar a memória alocada
    for (int i = 0; i < N; i++) {
        free(nomes[i]);
    }
    
    return 0;
}
