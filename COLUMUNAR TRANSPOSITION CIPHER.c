#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void gridStr(char *line, char *key);
char encrypt(char *key);
int main() {
    char key[50];
    char line[256];
    printf("Enter your string: ");
    if (fgets(line, sizeof line, stdin) == NULL) {
        fprintf(stderr, "No line read\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter your key: ");
    if (fgets(key, sizeof key, stdin) == NULL) {
        fprintf(stderr, "No line read\n");
        exit(EXIT_FAILURE);
    }
    
    int len = strlen(line);
    if (len && line[len - 1] == '\n')
        line[--len] = '\0';
        
    int len1 = strlen(key);
    if (len1 && key[len1 - 1] == '\n')
        key[--len]= '\0';
        
    gridStr(line, key);
    encrypt(key);
    }

        
void gridStr(char *line, char *key)
{    
    char mat[10][10] = {0};
    int columns = strlen(key)-1;
    int rows = 0;
    int i=0,j = 0;
    
    while (line[i]) {
        if (line[i] == ' ') {
            putchar('_');
        } else {
            putchar(line[i]);
        }
        mat[rows][i % columns] = line[i];
        i++;
        if (i > 0 && i % columns == 0) {
            putchar('\n');
            rows++;
        }
    }
    if (i % columns != 0)  putchar('\n');

    rows++; 0
    printf("\nMatrix:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (mat[i][j] == ' ') {
                putchar('_');
            } else {
                putchar(mat[i][j]);
            }
        }
        printf("\n");
    }
    
    
}

char encrypt(char *key){
    char temp;
    int i,j;
    int n = strlen(key);
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (key[i] > key[j]) {
                    temp = key[i];
                    key[i] = key[j];
                    key[j] = temp;
            }
        }
    }

    printf("encrypted text : %s", key);
    printf("decrypted text :%s");
    return 0;
}

