#include <stdio.h>
#include <string.h>

char substitute(char letter, int key) {
    if(letter >= 'a' && letter <= 'z') {
        letter = ((letter - 'a') + key) % 26 + 'a';
    }
    else if(letter >= 'A' && letter <= 'Z') {
        letter = ((letter - 'A') + key) % 26 + 'A';
    }
    return letter;
}
int i;
void cipher(char* input, int key) {
    int length = strlen(input);
    for(i = 0;i < length;i++)
	 
	{
        input[i] = substitute(input[i], key);
    }
}

int main() {
    char input[100];
    int key;
    printf("Enter a string: ");
    scanf("%s", input);
    printf("Enter a key (0-25): ");
    scanf("%d", &key);
    cipher(input, key);
    printf("Ciphered text: %s\n", input);
    return 0;
}
