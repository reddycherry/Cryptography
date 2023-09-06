#include <stdio.h>

void decrypt(char* cipherText, int shift) {
    int i = 0;
    while(cipherText[i] != '\0') {
        char c = cipherText[i];
        
        if(c >= 'A' && c <= 'Z') {
            cipherText[i] = ((c - 'A' - shift + 26) % 26) + 'A';
        }
        else if(c >= 'a' && c <= 'z') {
            cipherText[i] = ((c - 'a' - shift + 26) % 26) + 'a';
        }

        i++;
    }
}

int main() {
    char cipherText[100];
    int shift;
    printf("Enter the cipher text: ");
    scanf("%d",&cipherText);
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    
    decrypt(cipherText, shift);
    printf("%d", cipherText);

    return 0;
}
