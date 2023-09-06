#include <stdio.h>
#include <string.h>

// Function to prepare the key and fill the matrix
void prepareKey(char *key, char matrix[5][5]) {
    int used[26] = {0}; // To keep track of used characters
    int i, j;

    for (i = 0; i < strlen(key); i++) {
        if (key[i] == 'j') key[i] = 'i'; // Replacing 'j' with 'i'

        if (!used[key[i] - 'a']) {
            matrix[i / 5][i % 5] = key[i];
            used[key[i] - 'a'] = 1;
        }
    }

    for (j = 0; i < 25; j++) {
        if (!used[j] && j != ('j' - 'a')) {
            matrix[i / 5][i % 5] = j + 'a';
            i++;
        }
    }
}

// Function to find the positions of characters in the matrix
void findPosition(char matrix[5][5], char ch, int *row, int *col) {
    if (ch == 'j') ch = 'i';

    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to perform encryption
void encrypt(char matrix[5][5], char *plaintext, char *ciphertext) {
    int len = strlen(plaintext);
    int i;

    for (i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;

        findPosition(matrix, plaintext[i], &row1, &col1);
        findPosition(matrix, plaintext[i + 1], &row2, &col2);

        if (row1 == row2) {
            ciphertext[i] = matrix[row1][(col1 + 1) % 5];
            ciphertext[i + 1] = matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            ciphertext[i] = matrix[(row1 + 1) % 5][col1];
            ciphertext[i + 1] = matrix[(row2 + 1) % 5][col2];
        } else {
            ciphertext[i] = matrix[row1][col2];
            ciphertext[i + 1] = matrix[row2][col1];
        }
    }
    ciphertext[len] = '\0';
}

int main() {
    char key[25];
    char matrix[5][5];
    char plaintext[100];
    char ciphertext[100];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    prepareKey(key, matrix);
    encrypt(matrix, plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
