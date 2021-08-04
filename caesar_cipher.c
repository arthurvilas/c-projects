#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

void encrypt(char *message, int shift);

int main(void) {
    char message[MAX_LEN];
    int shift;

    printf("Enter a message to be encrypted: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the shift amount: ");
    scanf("%d", &shift);

    encrypt(message, shift);
    printf("Encrypted message: %s", message);

    return 0;
}

void encrypt(char *message, int shift) {
    for (char *p = message; *p; p++) {
        if (isalpha(*p)) {
            if (islower(*p)) {
                *p = (*p - 'a' + shift) % 26 + 'a';
            } else {
                *p = (*p - 'A' + shift) % 26 + 'A';
            }
        }
    }
}