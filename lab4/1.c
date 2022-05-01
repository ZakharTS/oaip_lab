#include <stdio.h>

int main() {
    int x, n1, n2, n3;
    printf("x = ");
    scanf("%d", &x);
    n1 = x % 10;
    x /= 10;
    n2 = x % 10;
    n3 = x;
    if(n1 == n2) {
        printf("False\n");
    } else if(n1 == n3) {
        printf("False\n");
    } else if(n2 == n3) {
        printf("False\n");
    } else {
        printf("True\n");
    }
    return 0;
}
