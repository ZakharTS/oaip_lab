#include <stdio.h>
#include <math.h>

int main() {
    int par;
    float a, r1, r2, s;
    printf("Enter element number: ");
    scanf("%d", &par);
    printf("Enter value: ");
    switch(par) {
        case 1: scanf("%f", &a); r1 = a * sqrt(3) / 6; r2 = a * sqrt(3) / 3; s = a * a * sqrt(3) / 4; printf("%f %f %f", r1, r2, s); break;
        case 2: scanf("%f", &r1); a = r1 * 6 / sqrt(3); r2 = 2 * r1; s = a * a * sqrt(3) / 4; printf("%f %f %f", a, r2, s); break;
        case 3: scanf("%f", &r2); a = r2 * 3 / sqrt(3); r1 = r2 / 2; s = a * a * sqrt(3) / 4; printf("%f %f %f", a, r1, s); break;
        case 4: scanf("%f", &s); a = sqrt(s * 4 / sqrt(3)); r1 = a * sqrt(3) / 6; r2 = a * sqrt(3) / 3; printf("%f %f %f", a, r1, r2); break;
    }
    printf("\n");
    return 0;
}
