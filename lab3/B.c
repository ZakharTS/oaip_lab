#include <stdio.h>

int main() {
    int x, n1, n2, res1, res2;
    printf("x = ");
    scanf("%d", &x);
    n1 = x % 10;
    x /= 10;
    n2 = x % 10;
    res1 = n1 + n2;
    res2 = n1 * n2;
    printf("sum = %d\nproduct = %d\n", res1, res2);
    return 0;
}
