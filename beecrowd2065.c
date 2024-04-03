#include <stdio.h>
#include <stdlib.h>

int TempoAtendimento(int N, int M, int tempos_funcionarios[], int itens_clientes[]) {
    int tempos_atendimento[N]; // Vetor para armazenar os tempos de atendimento dos funcionários
    int total_tempo = 0; // Variável para armazenar o tempo total

    // Inicializa os tempos de atendimento dos funcionários
    for (int i = 0; i < N; i++) {
        tempos_atendimento[i] = 0;
    }

    // Simulação do atendimento dos clientes
    for (int j = 0; j < M; j++) {
        int idx_funcionario = 0;
        // Encontra o funcionário livre
        for (int k = 1; k < N; k++) {
            if (tempos_atendimento[k] < tempos_atendimento[idx_funcionario]) {
                idx_funcionario = k;
            }
        }
        // Atualiza o tempo de atendimento do funcionário
        tempos_atendimento[idx_funcionario] += itens_clientes[j] * tempos_funcionarios[idx_funcionario];
        // Atualiza o tempo total
        if (tempos_atendimento[idx_funcionario] > total_tempo) {
            total_tempo = tempos_atendimento[idx_funcionario];
        }
    }

    return total_tempo;
}

int main () {
    int i, j;
    int N, M, tempo_total = 0;
    int *tempo_funcionarios, *itens_clientes;
    scanf("%d %d", &N, &M);

    tempo_funcionarios = (int*) malloc(N * sizeof(int));
    itens_clientes = (int*) malloc(M * sizeof(int));

    for (i = 0; i < N; i++) {
        scanf("%d", &tempo_funcionarios[i]);
    }

    for(j = 0; j < M; j++) {
        scanf("%d", &itens_clientes[j]);
    }

    tempo_total = TempoAtendimento(N, M, tempo_funcionarios, itens_clientes);

    printf("%d\n", tempo_total);

    free(tempo_funcionarios);
    free(itens_clientes);

    return 0;   
}