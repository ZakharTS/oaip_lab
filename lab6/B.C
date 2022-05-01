#include <stdio.h>

int main() {
    int sw = 0, n, m, k1, k2, a[20][20], i = 0, j = 0;
    printf("k1 = ");
    scanf("%d", &k1);
    printf("k2 = ");
    scanf("%d", &k2);
    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 1; i <= n; i++) {
        sw = a[i][k1];
        a[i][k1] = a[i][k2];
        a[i][k2] = sw;
        sw = 0;
    }
    for(i = 1; i <= m; i++) {
        sw = a[k1][i];
        a[k1][i] = a[k2][i];
        a[k2][i] = sw;
        sw = 0;
    }
    printf("\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
