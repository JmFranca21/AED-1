#include <stdio.h>
#include <string.h>

int main() {
    char expression[1001];
    
    while (fgets(expression, 1001, stdin) != NULL) {
        int balance = 0;
        int correct = 1;  // Assume the expression is correct initially
        
        for (int i = 0; i < strlen(expression); i++) {
            if (expression[i] == '(') {
                balance++;
            } else if (expression[i] == ')') {
                balance--;
                if (balance < 0) {
                    correct = 0;
                    break;
                }
            }
        }
        
        if (balance != 0) {
            correct = 0;
        }
        
        if (correct) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}
