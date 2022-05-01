#include <stdio.h>

int main(){
    int i = 0, n, min = 20000;
    printf("n = ");
    scanf("%d", &n );
    printf("Enter the numbers:\n");
    while(i < n){
        i++;
        int in;
        scanf("%d", &in);
        if(in <= 0) continue;
        if(in < min ) min = in;
    }
    printf("Minimum is %d", min);
    return 0;
}
