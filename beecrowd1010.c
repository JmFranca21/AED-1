#include <stdio.h>
 
int main() {
    int A, numA, B, numB;
    double valorA, valorB, total;

    scanf("%d %d %lf", &A, &numA, &valorA);
    scanf("%d %d %lf", &B, &numB, &valorB);
    
    total = (numA * valorA)+(numB * valorB);
    printf("VALOR A PAGAR: R$ %.2lf\n", total);

    return 0;
}