#include <stdio.h>
#include <math.h>

int main() {
    float x, y, z, res;
    printf("x = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%f", &y);
    printf("z = ");
    scanf("%f", &z);
    res = (exp(fabs(x - y)) * pow(fabs(x - y), x + y) / (atan(x) + atan(z))) + pow(pow(x, 6) + pow(log(y), 2), 1.0 / 3.0);
    printf("Result is %f\n", res);
    return 0;
}
