#include <stdio.h>

int main ()
{
    int N, i;
    scanf("%d", &N);
    i = 1;
    while(N-->0)
    {
        printf ("%d ", i++);
        printf ("%d ", i++);
        printf ("%d ", i++);
        printf("PUM\n");
        i++;
    }

 
    return 0;
}