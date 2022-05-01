#include <stdio.h>
#include <stdlib.h>

void TrimLeftC(char *str, char toTrim);
void del(char *str, size_t pos);

int main() {
    for (short i = 0; i < 5; i++) {
        char str[256], c;
        printf("Enter string: ");
        gets(str);
        printf("Character to trim: ");
        scanf("%c", &c);
        TrimLeftC(str, c);
        puts(str);
        printf("\n");
        fflush(stdin);
    }
    return 0;
}

void TrimLeftC(char *str, char toTrim) {
    size_t curSize = 0;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == toTrim && (str[i-1] == ' ' || i == 0)) {
            del(str, i);
        }
    }
}

void del(char *str, size_t pos) {
    for (size_t i = pos; str[i] != '\0'; i++) {
        str[i] = str[i+1];
    }
}
