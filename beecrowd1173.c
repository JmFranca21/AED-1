#include <stdio.h>
 
int main() {
 int N[10], i, X;
 scanf("%d", &X);
 
 for (i = 0; i < 10; i++) {
     if (i == 0){
        N[i] = X;    
     }
     else {
        N[i] = X*2;
     }
     printf("N[%d] = %d\n", i, X);
     X = X*2;
 }
 
 
    return 0;
}