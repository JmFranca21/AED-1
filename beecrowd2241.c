#include <stdio.h>

#define MAX_N 500

int tabuleiro[MAX_N][MAX_N];
int black_prefix[MAX_N + 1][MAX_N + 1];
int white_prefix[MAX_N + 1][MAX_N + 1];
int N, P;

void marcarPedras(int pedras, int jogador) {
    for (int i = 0; i < pedras; i++) {
        int L, C;
        scanf("%d %d", &L, &C);
        tabuleiro[L-1][C-1] = jogador;
    }
}

void preencherPrefixSums() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            black_prefix[i][j] = black_prefix[i-1][j] + black_prefix[i][j-1] - black_prefix[i-1][j-1];
            white_prefix[i][j] = white_prefix[i-1][j] + white_prefix[i][j-1] - white_prefix[i-1][j-1];
            if (tabuleiro[i-1][j-1] == 1) {
                black_prefix[i][j]++;
            } else if (tabuleiro[i-1][j-1] == 2) {
                white_prefix[i][j]++;
            }
        }
    }
}

int contarSubareas(int jogador) {
    int count = 0;

    for (int tamanho = 1; tamanho <= N; tamanho++) {
        for (int i = 0; i <= N - tamanho; i++) {
            for (int j = 0; j <= N - tamanho; j++) {
                int x1 = i + 1, y1 = j + 1;
                int x2 = i + tamanho, y2 = j + tamanho;

                int black_count = black_prefix[x2][y2] - black_prefix[x1-1][y2] - black_prefix[x2][y1-1] + black_prefix[x1-1][y1-1];
                int white_count = white_prefix[x2][y2] - white_prefix[x1-1][y2] - white_prefix[x2][y1-1] + white_prefix[x1-1][y1-1];

                if (jogador == 1 && black_count > 0 && white_count == 0) {
                    count++;
                } else if (jogador == 2 && white_count > 0 && black_count == 0) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    scanf("%d %d", &N, &P);

    marcarPedras(P, 1);  // Jogador das pedras pretas
    marcarPedras(P, 2);  // Jogador das pedras brancas

    preencherPrefixSums();

    int pretas = contarSubareas(1);
    int brancas = contarSubareas(2);

    printf("%d %d\n", pretas, brancas);

    return 0;
}
