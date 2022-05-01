#include <stdio.h>
#include <math.h>

int main(){
    float res, x, a, b, h;
    printf("a = ");
    scanf("%f",&a);
    printf("b = ");
    scanf("%f",&b);
    printf("h = ");
    scanf("%f",&h);
    x = a;
    do {
        if(fabs(x - (a + (2.0 * h))) < 0.000001){ x += h; continue; }
        res = sqrt(x) * cosh(x);
        printf("f(%.1f) = %.3f\n", x, res);
        x += h;
    }
    while(x <= b);
    return 0;
}
