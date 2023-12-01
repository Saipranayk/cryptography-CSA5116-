#include <stdio.h>
#include <string.h>

void decrypt(char *text, char key[26]) {
    for (int i = 0; i < strlen(text); i++) {
        if (isupper(text[i]))
            text[i] = key[text[i] - 'A'];
        else if (islower(text[i]))
            text[i] = key[text[i] - 'a'];
    }
}

int main() {
    char text[] = "D CBA XYZ ABCD XYZ";
    char key[26] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    decrypt(text, key);
    printf("Decrypted text: %s\n", text);
    return 0;
}
