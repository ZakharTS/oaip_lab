#include <stdio.h>
#include <stdlib.h>

int main() {
 int n, k, i, reps = 1, j = 0;
 int *pa;
 int *pb;
 printf("n = ");
 scanf("%d", &n);
 pa = (int *)malloc(n*sizeof(int));
 pb = (int *)malloc(n*sizeof(int));
 for(i = 0; i < n; i++) {
  scanf("%d", (pa+i));
 }
 for(i = 1; i <= n; i++) {
  if(*(pa+i) == *(pa+(i-1))) {
   reps++;
  } else {
   *(pb+j) = reps;
   j++;
   reps = 1;
  }
 }

 for(i = 0; i < j; i++) {
  printf("%d ", *(pb+i));
 }
 printf("\nValue to delete: ");
 scanf("%d", &n);
 for(i = 0; i < j; i++) {
  if(*(pb+i) == n) {
   j--;
   for(k = i; k < j; k++) {
    *(pb+k) = *(pb+k+1);
   }
  }
 }

 for(i = 0; i < j; i++) {
  printf("%d ", *(pb+i));
 }
 free(pa);
 free(pb);
 return 0;
}
