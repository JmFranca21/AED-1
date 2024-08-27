#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int m;
        scanf("%d", &m);

        int original[m], sorted[m];
        for (int i = 0; i < m; i++) {
            scanf("%d", &original[i]);
            sorted[i] = original[i];
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < m - i - 1; j++) {
                if (sorted[j] < sorted[j + 1]) {
                    int temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            if (original[i] == sorted[i]) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
