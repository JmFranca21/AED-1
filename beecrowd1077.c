#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 300

typedef struct {
    char items[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char value) {
    if (!isFull(s)) {
        s->items[++(s->top)] = value;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    initStack(&stack);
    int i, k = 0;
    
    for (i = 0; infix[i]; i++) {
        if (isspace(infix[i])) {
            continue;
        }
        
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) != '(') {
                return;
            } else {
                pop(&stack);
            }
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(infix[i])) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }
    
    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }
    
    postfix[k] = '\0';
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();  // Consume newline character after integer input
    
    for (int i = 0; i < n; i++) {
        char infix[MAX], postfix[MAX];
        fgets(infix, MAX, stdin);
        infix[strcspn(infix, "\n")] = '\0';  // Remove trailing newline character
        infixToPostfix(infix, postfix);
        printf("%s\n", postfix);
    }
    
    return 0;
}



