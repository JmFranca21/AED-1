#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcao recebe a matriz, percorre as linhas e colunas preenchendo os valores
void preenche_matriz(int matriz[][9]) {
    int i, j;
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Funcao recebe a matriz, percorre as linhas e verifica se ha valores repetidos
int verifica_linhas(int matriz[][9]) {
    int i = 0, j, aux = 0, cont = 0;
        for(i = 0; i < 9; i++) {
            for(aux = 1; aux <= 9; aux++) {
                cont = 0;
                 for(j = 0; j < 9; j++) {
                    if (matriz[i][j] == aux) {
                        cont++;
                        if (cont != 1) {
                            return 0;
                        }
                    }
                }
            }
        }
    return 1;
}

// Funcao recebe a matriz, percorre as colunas e verifica se ha valores repetidos
int verifica_colunas(int matriz[][9]) {
     int i = 0, j, aux = 0, cont;
        for(j = 0; j < 9; j++) {
            for(aux = 1; aux <= 9; aux++) {
                cont = 0;
                 for(i = 0; i < 9; i++) {
                    if (matriz[i][j] == aux) {
                        cont++;
                        if (cont != 1) {
                            return 0;
                        }
                    }
                }
            }
        }
    return 1;
}

// Funcao recebe a matriz, percorre os blocos e verifica se ha valores repetidos
int verifica_blocos(int matriz[][9]) {
    int i, j, aux, cont = 0, linha, coluna;
    for(i = 0; i < 9; i += 3) {
        for(j = 0; j < 9; j += 3) {
            for(aux = 1; aux <= 9; aux++) {
                cont = 0;
                for(linha = i; linha < i + 3; linha++) {
                    for(coluna = j; coluna < j + 3; coluna++) {
                        if (matriz[linha][coluna] == aux) {
                            cont++;
                            if (cont != 1) {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;

}

int main () {
    int instancias = 0, matriz[9][9], i, linha, coluna, bloco;

    while(instancias <= 0) {
        scanf("%d", &instancias);
    }

    int resp[instancias];

    for(i = 1; i <= instancias; i++) {
        preenche_matriz(matriz);
        linha = verifica_linhas(matriz);
        coluna = verifica_colunas(matriz);
        bloco = verifica_blocos(matriz);

        if (linha == 1 && coluna == 1 && bloco == 1) {
            resp[i] = 1;
        } else {
            resp[i] = 0;
        }
    }

    for(i = 1; i <= instancias; i++) {
        if(resp[i] == 1) {
            printf("Instancia %d\nSIM\n\n", i);
        } else {
            printf("Instancia %d\nNAO\n\n", i);
        }
    }

    
    return 0;
}
