
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESSAGESIZE 1000

void decrypt(char cipher[], int shift) {
    
    int i = 0;

    while (cipher[i] != '\0') {

        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
            cipher[i] = (cipher[i] - 'A' - shift) % 26 + 'A';
        }

        else if (cipher[i] >= 'a' && cipher[i] <= 'z') {
            cipher[i] = (cipher[i] - 'a' - shift) % 26 + 'a';
        }

        i++;
    }

    printf("%s\n", cipher);
}


int main() {
    
    char message[MESSAGESIZE];
    FILE *f;
    
    f = fopen("input.txt", "r");
    if (!f) {
        printf("[Error] Create the filename 'input.txt'\n");
        exit(-1);
    }
    fgets(message, MESSAGESIZE, f);
    fclose(f);

    message[strlen(message) - 1] = '\0';

    decrypt(message, 13);

    return 0;
}
