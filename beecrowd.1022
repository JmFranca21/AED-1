#include <stdio.h>

// Função para calcular o MDC (Máximo Divisor Comum) usando o algoritmo de Euclides
int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int n1, d1, n2, d2, num, den, divisor;
        char op, ch;

        // Leitura da expressão no formato N1 / D1 OP N2 / D2
        scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);

        switch (op) {
            case '+':
                num = n1 * d2 + n2 * d1;
                den = d1 * d2;
                break;
            case '-':
                num = n1 * d2 - n2 * d1;
                den = d1 * d2;
                break;
            case '*':
                num = n1 * n2;
                den = d1 * d2;
                break;
            case '/':
                num = n1 * d2;
                den = n2 * d1;
                break;
        }

        // Simplificação do resultado
        if (den < 0) {  // Garantir que o denominador seja positivo
            num = -num;
            den = -den;
        }
        divisor = mdc(abs(num), abs(den)); // Corrigir para calcular o MDC de valores absolutos
        int simpl_num = num / divisor;
        int simpl_den = den / divisor;

        // Apresentação do resultado
        printf("%d/%d = %d/%d\n", num, den, simpl_num, simpl_den);
    }

    return 0;
}
