#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR 1001
#define MAX_STACK 1000

// Function to check if a character is an operand
int isOperand(char c) {
    return isalnum(c); // Check if it's a letter or a digit
}

// Function to check if a character is an operator
int isOperator(char c) {
    return c == '^' || c == '*' || c == '/' || c == '+' || c == '-' ||
           c == '>' || c == '<' || c == '=' || c == '#' || c == '.' || c == '|';
}

// Function to get the precedence of an operator
int precedence(char op) {
    switch (op) {
        case '^': return 6;
        case '*': case '/': return 5;
        case '+': case '-': return 4;
        case '>': case '<': case '=': case '#': return 3;
        case '.': return 2; // AND
        case '|': return 1; // OR
        default: return 0;
    }
}

// Function to check if the operator is left associative
int isLeftAssociative(char op) {
    return op != '^'; // ^ is right associative, others are left associative
}

// Function to perform lexical check
int lexicalCheck(const char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        if (!isOperand(expr[i]) && !isOperator(expr[i]) && expr[i] != '(' && expr[i] != ')') {
            return 0; // Lexical error
        }
    }
    return 1;
}

// Function to perform syntax check and convert to postfix
int syntaxCheck(const char* expr, char* postfix) {
    char stack[MAX_STACK];
    int top = -1;
    int j = 0;
    int expectOperand = 1; // Initially, expect an operand or '('

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (isOperand(c)) {
            if (!expectOperand) return 0; // Syntax error
            postfix[j++] = c;
            expectOperand = 0; // After an operand, expect an operator or ')'
        }
        else if (isOperator(c)) {
            if (expectOperand) return 0; // Syntax error
            while (top != -1 && isOperator(stack[top]) &&
                   ((isLeftAssociative(c) && precedence(c) <= precedence(stack[top])) ||
                    (!isLeftAssociative(c) && precedence(c) < precedence(stack[top])))) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
            expectOperand = 1; // After an operator, expect an operand or '('
        }
        else if (c == '(') {
            stack[++top] = c;
            expectOperand = 1; // After '(', expect an operand
        }
        else if (c == ')') {
            int foundOpeningParen = 0;
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top == -1 || stack[top] != '(') return 0; // Syntax error: Unmatched ')'
            top--; // Pop the '('
            foundOpeningParen = 1;
            expectOperand = 0; // After ')', expect an operator or end of expression
        }
    }

    while (top != -1) {
        if (stack[top] == '(' || stack[top] == ')') return 0; // Syntax error: Unmatched '('
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
    return !expectOperand; // If true, it means the expression ended correctly
}

int main() {
    char expr[MAX_EXPR];
    char postfix[MAX_EXPR];

    while (fgets(expr, MAX_EXPR, stdin) != NULL) {
        // Remove the newline character at the end if present
        expr[strcspn(expr, "\n")] = '\0';

        if (!lexicalCheck(expr)) {
            printf("Lexical Error!\n");
        }
        else if (!syntaxCheck(expr, postfix)) {
            printf("Syntax Error!\n");
        }
        else {
            printf("%s\n", postfix);
        }
    }

    return 0;
}
