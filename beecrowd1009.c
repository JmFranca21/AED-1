#include <stdio.h>
 
int main() {
    
        char nome[50];
        double salario, total, vendas;
        
        scanf("%s", &nome);
        scanf("%lf", &salario);
        scanf("%lf", &vendas);
        
        total = salario + (0.15*vendas);
        
        printf("TOTAL = R$ %.2lf\n", total);
 
    return 0;
}