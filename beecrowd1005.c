#include <stdio.h>
 
double Media () {
    double A, B, MEDIA;
    scanf("%lf %lf", &A, &B);
    MEDIA = ((A*3.5)+(B*7.5))/11;
    return MEDIA;
}

int main() {
    double MEDIA;
    MEDIA = Media();
    printf("MEDIA = %.5lf\n", MEDIA);
    return 0;
}