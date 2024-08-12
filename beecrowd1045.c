#include <stdio.h>

int main() 
{
    double  A, B, C, T;
    scanf(" %lf %lf %lf", &A, &B, &C);

    if (B > A)
    {
        T = B; 
        B = A; 
        A = T;
    }
    
    if (C > A)
    {
        T = C;
        C = A;
        A = T;
    }
    
    if (C > B)
    {
        T = C;
        C = B;
        B = T;
    }
    
    if (A >= (B+C))
        printf("NAO FORMA TRIANGULO\n");
        
    else 
    {
        if ((A*A) == (B*B) + (C*C))
            printf("TRIANGULO RETANGULO\n");
        else if ((A*A) > (B*B) + (C*C))
            printf("TRIANGULO OBTUSANGULO\n");
        else if ((A*A) < (B*B) + (C*C))
            printf("TRIANGULO ACUTANGULO\n");
  
        if ((A==B)&&(A==C))
            printf("TRIANGULO EQUILATERO\n");
        else if ((A==B)||(A==C)||(B==C))
            printf("TRIANGULO ISOSCELES\n");
    }
    
    return 0;
}