/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cel {
	char palavra[20];
	struct cel* seg;
};

typedef struct cel Celula;

void PreencheCelula (Celula* lst, char aux[]) {
	Celula* nova;
	int i;
	nova = malloc(sizeof(Celula));
	for(i = 0; i <= 20; i++) {
		nova->palavra[i] = aux[i];
	}
	nova->seg = lst->seg;
	lst->seg = nova;
}

void LimpezaAuxiliar (char aux[]) {
	int i;
	
}

void ExcluiRepetidos (Celula* lst) {
	Celula *p, *q, *r;
	int result;
	
	
}

void ImprimaCelulas (Celula* lst) {
	Celula *p;
	for (p = lst->seg; p != NULL; p = p->seg) {
		printf("%s", p->palavra);
	}
}

int main() {

	int N = 0, cont = 0, i, j = 0;
	char str[21000], aux[20];

	Celula* lst;
	lst = malloc(sizeof(Celula));
	lst->seg = NULL;
	
	while (N > 100 || N < 1) {
		scanf("%d", &N);
	}

	while (cont <= N) {
		fgets(str, 21000, stdin);
		for(i = 0; i < strlen(str); i++, j++) {
			if (str[i] != ' ' || str[i] != '\n') {
				aux[j] = str[i];
			}

			if (str[i] == ' ' || str[i] == '\n') {
				LimpezaAuxiliar(aux);
				PreencheCelula (lst, aux);
				j = 0;
			}

		}
		cont++;
	}
	ImprimaCelulas(lst);
	
  	return 0;
} */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_LENGTH 20

// Estrutura para um nó da lista encadeada
struct cel {
    char palavra[MAX_ITEM_LENGTH + 1];
    struct cel* seg;
};

typedef struct cel Celula;

// Função para criar um novo nó
Celula* createNode(const char* item) {
    Celula* nova = (Celula *)malloc(sizeof(Celula));
    if (nova == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(nova->palavra, item);
    nova->seg = NULL;
    return nova;
}

// Função para adicionar um item à lista encadeada, evitando duplicatas
void addItem(Celula** lst, const char* item) {
    Celula* current = *lst;
    Celula* prev = NULL;

    // Verificar duplicatas
    while (current != NULL) {
        if (strcmp(current->palavra, item) == 0) {
            return; // Item duplicado, não adiciona
        }
        prev = current;
        current = current->seg;
    }

    // Adicionar novo nó ao final da lista
    Celula* nova = createNode(item);
    if (prev == NULL) {
        // Lista está vazia
        *lst = nova;
    } else {
        prev->seg = nova;
    }
}

// Função para ordenar a lista encadeada alfabeticamente
void sortList(Celula** lst) {
    Celula* current = *lst;
    Celula* index = NULL;
    char temp[MAX_ITEM_LENGTH + 1];

    // Ordenar a lista usando um algoritmo de ordenação simples
    while (current != NULL) {
        index = current->seg;
        while (index != NULL) {
            if (strcmp(current->palavra, index->palavra) > 0) {
                // Trocar os itens
                strcpy(temp, current->palavra);
                strcpy(current->palavra, index->palavra);
                strcpy(index->palavra, temp);
            }
            index = index->seg;
        }
        current = current->seg;
    }
}

// Função para imprimir os itens da lista encadeada com espaço entre eles
void printList(Celula* lst) {
    Celula* current = lst;
    while (current != NULL) {
        printf("%s", current->palavra);
        if (current->seg != NULL) {
            printf(" ");
        }
        current = current->seg;
    }
    printf("\n");
}

// Função para liberar a memória da lista encadeada
void freeList(Celula** lst) {
    Celula* current = *lst;
    Celula* next;

    while (current != NULL) {
        next = current->seg;
        free(current);
        current = next;
    }

    *lst = NULL;
}

// Função principal
int main() {
    int N = 0, cont = 0, i, j = 0;
    char str[21000], aux[MAX_ITEM_LENGTH + 1];

    Celula* lst = (Celula *)malloc(sizeof(Celula));
    lst->seg = NULL;
    
    // Leitura do número de casos
    while (N <= 0 || N > 100) {
        scanf("%d", &N);
        getchar(); // Consumir o caractere de nova linha
    }

    while (cont < N) {
        // Limpar a string auxiliar
        memset(aux, 0, sizeof(aux));
        
        fgets(str, sizeof(str), stdin);
        i = 0;
        j = 0;
        
        // Processar a linha de entrada caractere por caractere
        while (str[i] != '\0') {
            // Adicionar caractere a `aux` se não for um espaço ou nova linha
            if (str[i] != ' ' && str[i] != '\n') {
                aux[j] = str[i];
                j++;
            } else {
                // Quando encontra espaço ou nova linha, processar `aux`
                if (j > 0) {
                    aux[j] = '\0'; // Termina a string `aux`
                    addItem(&lst, aux);
                    // Limpar a string auxiliar
                    memset(aux, 0, sizeof(aux));
                    j = 0;
                }
            }
            i++;
        }
        
        // Ordenar a lista encadeada alfabeticamente
        sortList(&lst);

        // Imprimir os itens da lista organizada
        printList(lst);

        // Liberar a memória da lista encadeada
        freeList(&lst);
        
        // Incrementar o contador de casos de teste
        cont++;
    }

    return 0;
}
