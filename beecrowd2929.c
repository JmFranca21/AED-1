#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Estrutura para a pilha com duas pilhas internas
typedef struct {
    int *stack;
    int *min_stack;
    int top;
    int min_top;
    int capacity;
} Stack;

// Função para inicializar a pilha
Stack* createStack(int capacity) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->min_top = -1;
    s->stack = (int*)malloc(capacity * sizeof(int));
    s->min_stack = (int*)malloc(capacity * sizeof(int));
    return s;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Função para empilhar um elemento
void push(Stack *s, int value) {
    s->stack[++s->top] = value;
    if (s->min_top == -1 || value <= s->min_stack[s->min_top]) {
        s->min_stack[++s->min_top] = value;
    }
}

// Função para desempilhar um elemento
void pop(Stack *s) {
    if (!isEmpty(s)) {
        int value = s->stack[s->top--];
        if (value == s->min_stack[s->min_top]) {
            s->min_top--;
        }
    }
}

// Função para obter o menor elemento da pilha
int getMin(Stack *s) {
    if (isEmpty(s)) {
        return INT_MAX;  // Indicador de pilha vazia
    }
    return s->min_stack[s->min_top];
}

int main() {
    int N;
    scanf("%d", &N);
    
    Stack *s = createStack(N);

    for (int i = 0; i < N; i++) {
        char operation[5];
        scanf("%s", operation);

        if (operation[1] == 'U') {  // PUSH
            int value;
            scanf("%d", &value);
            push(s, value);
        } else if (operation[1] == 'O') {  // POP
            if (isEmpty(s)) {
                printf("EMPTY\n");
            } else {
                pop(s);
            }
        } else if (operation[1] == 'I') {  // MIN
            int min_value = getMin(s);
            if (min_value == INT_MAX) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", min_value);
            }
        }
    }

    // Libera memória alocada
    free(s->stack);
    free(s->min_stack);
    free(s);

    return 0;
}
