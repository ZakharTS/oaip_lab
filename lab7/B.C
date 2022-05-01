#include <stdio.h>
#include <stdlib.h>

int main() {
  int el, sw = 0, n, m, k1, k2, i = 0, j = 0, **a;
  printf("k1 = "); scanf("%d", &k1);
  printf("k2 = "); scanf("%d", &k2);
  printf("n = "); scanf("%d", &n);
  printf("m = "); scanf("%d", &m);
  k1--; k2--;
  a = (int **)malloc((n+1)*sizeof(int *));
  for(i = 0; i < n + 1; i++) a[i] = (int *)malloc((m)*sizeof(int));
  for(i = 0; i < n; i++) for(j = 0; j < m; j++) scanf("%d", &a[i][j]);
  for(i = 0; i < n; i++) {
   sw = a[i][k1];
   a[i][k1] = a[i][k2];
   a[i][k2] = sw;
   sw = 0;
  }
  printf("\n");
  for(i = 0; i < n; i++) {
   for(j = 0; j < m; j++) printf("%d ", a[i][j]);
   printf("\n");
  }
  for(i = 0; i < m; i++) {
   sw = a[k1][i];
   a[k1][i] = a[k2][i];
   a[k2][i] = sw;
   sw = 0;
  }
  printf("\n");
  for(i = 0; i < n; i++) {
   for(j = 0; j < m; j++) printf("%d ", a[i][j]);
   printf("\n");
  }
  printf("Line number: "); scanf("%d", &k1);
  n++; k1--;
  printf("Line: ");
  for(j = 0; j < m; j++) {
   scanf("%d", &el);
   for(i = n - 1; i > k1; i--) a[i][j] = a[i-1][j];
   a[k1][j] = el;
  }
  for(i = 0; i < n; i++) {
   for(j = 0; j < m; j++) printf("%d ", a[i][j]);
   printf("\n");
  }
  for(i = 0; i < n; i++) free(a[i]);
  free(a);
 return 0;
}
