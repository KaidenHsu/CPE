#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num1[1000005], num2[1000005], carry[1000005], answer[1000005];

int main(void)
{
  int n, m, i, j;
  scanf("%d", &n);

  for (i = 0; i < n; ++i) {
    scanf("%d", &m);
    memset(num1, 0 ,sizeof(num1));
    memset(num2, 0 ,sizeof(num2));
    memset(answer, 0 ,sizeof(carry));
    memset(answer, 0 ,sizeof(answer));

    for (int j = m - 1; j >= 0; j--) {
      scanf("%d%d", &num1[j], &num2[j]);
    }

    for (int j = 0; j <= m - 1; j++) {
      answer[j] = (carry[j] + num1[j] + num2[j]) % 10;
      carry[j + 1] = (carry[j] + num1[j] + num2[j]) / 10;
    }

    printf("\n");
    if(carry[m] != 0) printf("%d", carry[m]);
    for(j = m - 1 ; j >= 0 ; j--)
      printf("%d", answer[j]);
    printf("\n");
  }

  return 0;
}
