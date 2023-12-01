#include <stdio.h>
#include <string.h>

char substitute(char letter, int key) {
    int alphabet_size = 26;
    if(letter >= 'a' && letter <= 'z') {
        letter = ((letter - 'a') + key) % alphabet_size + 'a';
    }
    else if(letter >= 'A' && letter <= 'Z') {
        letter = ((letter - 'A') + key) % alphabet_size + 'A';
    }
    return letter;
}

void cipher(char* input, int* keys) {
    int length = strlen(input);
    for(int i = 0; i < length; i++) {
        input[i] = substitute(input[i], keys[i % 10]);
    }
}

int main() {
    char input[100];
    int keys[10] = {3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    printf("Enter a string: ");
    scanf("%s", input);
    cipher(input, keys);
    printf("Ciphered text: %s\n", input);
    return 0;
}
