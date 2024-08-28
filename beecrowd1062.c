#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    
    while (scanf("%d", &N), N != 0) {
        while (1) {
            int stack[1000];
            int top = 0;
            int i, x, expected = 1;
            
            scanf("%d", &x);
            if (x == 0) {
                break;
            }

            int possible = 1;
            for (i = 1; i <= N; i++) {
                while (expected <= N && (top == 0 || stack[top - 1] != x)) {
                    stack[top++] = expected++;
                }
                
                if (stack[top - 1] == x) {
                    top--;
                } else {
                    possible = 0;
                }
                
                if (i < N) {
                    scanf("%d", &x);
                }
            }
            
            if (possible) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        printf("\n");
    }

    return 0;
}
