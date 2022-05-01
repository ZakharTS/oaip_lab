#include <stdio.h>

int main() {
    int n, i, a[200], b[200], reps = 1, j = 0;
    printf("n = ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(i = 1; i <= n; i++) {
        if(a[i] == a[i-1]) {
            reps++;
        } else {
            b[j] = reps;
            j++;
            reps = 1;
        }
    }
    for(i = 0; i < j; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}
