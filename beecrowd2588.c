#include <stdio.h>
#include <string.h>

int countLettersToAdd(char sequence[]) {
    int count[26] = {0}; // Array to count the occurrences of each letter
    int oddCount = 0; // Count of letters with odd occurrences

    // Count the occurrences of each letter in the sequence
    for (int i = 0; i < strlen(sequence); i++) {
        count[sequence[i] - 'a']++;
    } 

    // Count the number of letters with odd occurrences
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) {
            oddCount++;
        }
    }

    // Return the minimum number of letters to add
    if (oddCount > 0) {
        return oddCount - 1;
    } else {
        return 0;
    }
}

int main() {
    char sequence[1001];

    while (scanf("%s", sequence) != EOF) {
        int lettersToAdd = countLettersToAdd(sequence);
        printf("%d\n", lettersToAdd);
    }

    return 0;
}