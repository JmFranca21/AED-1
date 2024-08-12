#include <stdio.h>
 
int main() {
    int N, cem, cinq, vinte, dez, cinco, dois, um;
    scanf("%d", &N);
    0<N<1000000;
    cem = N/100;
    cinq = (N%100)/50;
    vinte = ((N%100)%50)/20;
    dez = (((N%100)%50)%20)/10;
    cinco = ((((N%100)%50)%20)%10)/5;
    dois = (((((N%100)%50)%20)%10)%5)/2;
    um = ((((((N%100)%50)%20)%10)%5)%2)/1;
    printf("%d\n%d nota(s) de R$ 100,00\n%d nota(s) de R$ 50,00\n%d nota(s) de R$ 20,00\n%d nota(s) de R$ 10,00\n%d nota(s) de R$ 5,00\n%d nota(s) de R$ 2,00\n%d nota(s) de R$ 1,00\n", N, cem, cinq, vinte, dez, cinco, dois, um);
    
    return 0;
}