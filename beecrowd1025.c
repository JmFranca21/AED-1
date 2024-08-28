#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to find the first occurrence using binary search
int findFirstOccurrence(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            result = mid;  // Found, but continue to check if there's an earlier occurrence
            high = mid - 1;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int N, Q;
    int caseNumber = 0;

    while (scanf("%d %d", &N, &Q) && N != 0) {
        caseNumber++;
        int marbles[N];
        int queries[Q];

        // Read marbles
        for (int i = 0; i < N; i++) {
            scanf("%d", &marbles[i]);
        }

        // Sort the marbles
        qsort(marbles, N, sizeof(int), compare);

        // Read queries
        for (int i = 0; i < Q; i++) {
            scanf("%d", &queries[i]);
        }

        // Output case number
        printf("CASE# %d:\n", caseNumber);

        // Process each query
        for (int i = 0; i < Q; i++) {
            int query = queries[i];
            int index = findFirstOccurrence(marbles, N, query);

            if (index != -1) {
                printf("%d found at %d\n", query, index + 1);  // +1 for 1-based index
            } else {
                printf("%d not found\n", query);
            }
        }
    }

    return 0;
}
