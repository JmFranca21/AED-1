#include <stdio.h>
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
}