#include <stdio.h>

int main() {

     int i,N[20], j;

    for(i=0;i<20;i++){
        scanf("%i",&N[i]);
    }

    for(i=0;i<10;i++){
        j = N[i];
        N[i] = N[19-i];
        N[19-i]= j;
    }

    for(i=0;i<20;i++){
        printf("N[%i] = %i\n",i,N[i]);
    }

    return 0;
}