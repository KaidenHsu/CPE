#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char a[1001], b[1001];
  int i, j, count_a[123], count_b[123];

  while(fgets(a,10000, stdin)){
    memset(count_a, 0, sizeof(count_a));
    memset(count_b, 0, sizeof(count_b));
    for (i = 0; i < strlen(a); ++i) {
      count_a[a[i]]++;
    }
    fgets(b,10000,stdin);
    for (i = 0; i < strlen(b); ++i) {
      count_b[b[i]]++;
    }

    for (i = 97; i < 123; ++i) {
       j = 0;
       while(j < count_a[i] && j < count_b[i]){
         printf("%c", i);
         j++;
       }
    }

    printf("\n");
  }

  return 0;
}
