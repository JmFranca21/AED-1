#include <stdio.h>
#include <stdlib.h>

// Função para ler inteiros de uma linha de entrada
void ler_inteiros(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int N, M;
    
    // Lê o número de pessoas inicialmente na fila
    scanf("%d", &N);
    int fila_inicial[N];
    ler_inteiros(fila_inicial, N);

    // Lê o número de pessoas que deixaram a fila
    scanf("%d", &M);
    int sairam[M];
    ler_inteiros(sairam, M);

    // Usando um array para marcar os que saíram (valores de 1 a 100000)
    int saiu[100001] = {0};
    for (int i = 0; i < M; i++) {
        saiu[sairam[i]] = 1;
    }

    // Construindo a fila final
    int fila_final[N - M];
    int idx = 0;
    for (int i = 0; i < N; i++) {
        if (!saiu[fila_inicial[i]]) {
            fila_final[idx++] = fila_inicial[i];
        }
    }

    // Imprimindo o resultado
    for (int i = 0; i < N - M; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", fila_final[i]);
    }
    printf("\n");

    return 0;
}
