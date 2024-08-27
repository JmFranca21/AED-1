#include <stdio.h>

int main ()
{
    double M[12] [12];
    int i, j;
    char opcao[5];
    double soma = 0.0;
    
    scanf ("%c", &opcao);
    for (i = 0; i < 12; i++)
    for (j = 0; j < 12; j++)
        scanf("%lf", &M[i] [j]);
        
    for (i = 0; i < 12; i++)
    for (j = i+1; j < 12; j++)
        soma = soma + M[i] [j];
        
    if(opcao[0] == 'M') soma = soma/66.0;
    printf("%.1lf\n", soma);
    
    return 0;
}