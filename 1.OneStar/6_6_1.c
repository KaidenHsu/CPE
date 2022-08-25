#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000

int X[MAX_SIZE];

int comp(const void *a, const void *b){
  return (*(int *)a) - (*(int *)b);
}

void find_mid(int *X, int n){
  int min, max, nx, np, i;

  qsort(X, n, sizeof(int), comp);

  if (n % 2) {
    min = X[n / 2];
    nx = 1;
    np = 1;
  }else{
    min = X[n / 2 - 1], max = X[n / 2];
    nx = 2;
    np = max - min + 1;
  }

  printf("%d %d %d\n", min, nx, np);
}

int main(void)
{
  int n, i;
  while (scanf("%d", &n) != EOF) {
    for(i = 0; i < n; i++) scanf("%d", &X[i]);
    find_mid(X,n);
  }
  return 0;
}
