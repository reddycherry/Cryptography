#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char matrix[SIZE][SIZE];

void create_matrix(char *key) {
    int flag[26] = {0}, k = 0, len = strlen(key);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            while (k < len && flag[tolower(key[k]) - 'a']) k++;
            
            if (k < len) {
                matrix[i][j] = tolower(key[k]);
                flag[matrix[i][j] - 'a'] = 1;
            } else {
                for (int m = 0; m < 26; m++) {
                    if (!flag[m] && (m + 'a') != 'j') {
                        matrix[i][j] = m + 'a';
                        flag[m] = 1;
                        break;
                    }
                }
            }
        }
    }
}

void encrypt(char a, char b) {
    int x1, x2, y1, y2;
    
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == a) { x1 = i; y1 = j; }
            if (matrix[i][j] == b) { x2 = i; y2 = j; }
        }
            
    if (x1 == x2) {
        printf("%c%c", matrix[x1][(y1 + 1) % SIZE], matrix[x2][(y2 + 1) % SIZE]);
    } else if (y1 == y2) {
        printf("%c%c", matrix[(x1 + 1) % SIZE][y1], matrix[(x2 + 1) % SIZE][y2]);
    } else {
        printf("%c%c", matrix[x1][y2], matrix[x2][y1]);
    }
}

int main() {
    char key[30], text[30];
    
    printf("Enter key: ");
    scanf("%s", key);
    printf("Enter plaintext (even length): ");
    scanf("%s", text);
    
    create_matrix(key);
    
    for (int i = 0; i < strlen(text); i+=2)
        encrypt(text[i], text[i+1]);

    printf("\n");
    return 0;
}
