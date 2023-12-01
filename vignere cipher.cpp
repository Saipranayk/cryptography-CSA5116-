#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char *plaintext, char *key) {
    int i, j;
    int plaintextLen = strlen(plaintext);
    int keyLen = strlen(key);
    for (i = 0, j = 0; i < plaintextLen; ++i, ++j) {
        if (j == keyLen) {
            j = 0; 
        }
        if (isupper(plaintext[i])) {
            plaintext[i] = ((plaintext[i] + key[j] - 2 * 'A') % 26) + 'A';
        }
        else if (islower(plaintext[i])) {
            plaintext[i] = ((plaintext[i] + key[j] - 2 * 'a') % 26) + 'a';
        }
    }
}
void vigenereDecrypt(char *ciphertext, char *key) {
    int i, j;
    int ciphertextLen = strlen(ciphertext);
    int keyLen = strlen(key);
    for (i = 0, j = 0; i < ciphertextLen; ++i, ++j) {
        if (j == keyLen) {
            j = 0;
        }
        if (isupper(ciphertext[i])) {
            ciphertext[i] = ((ciphertext[i] - key[j] + 26) % 26) + 'A';
        }
        else if (islower(ciphertext[i])) {
            ciphertext[i] = ((ciphertext[i] - key[j] + 26) % 26) + 'a';
        }
    }
}
int main() {
    char input[100];
    char key[100];
    printf("Enter text: ");
    scanf("%99[^\n]", input);
    getchar();
    printf("Enter key: ");
    scanf("\n", key);  
    getchar();
    vigenereEncrypt(input, key);
    printf("Encrypted text: %s\n", input);
    vigenereDecrypt(input, key);
    printf("Decrypted text: %s\n", input);
    return 0;
}

