#include <stdio.h>
#include <string.h>

// Function to encrypt a message using the Caesar cipher
void caesarEncrypt(char message[], int shift) {
    int i = 0;
    char ch;

    while (message[i] != '\0') {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = (ch + shift - 'a') % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + shift - 'A') % 26 + 'A';
        }

        message[i] = ch;
        i++;
    }
}

int main() {
    char message[100];
    int shift;

    printf("Enter a message: ");
    gets(message);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    caesarEncrypt(message, shift);

    printf("Encrypted message: %s\n", message);

    return 0;
}
