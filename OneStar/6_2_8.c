#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int cases, n, i, j, f, c = 1;
  long long m[100][100];
  char tmp[100];
  scanf("%d", &cases);

  while (c <= cases) {
    scanf("%s%s%d", tmp, tmp, &n);
    f = 1;

    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        scanf("%lld", &m[i][j]);
        if (m[i][j] < 0) f = 0;
      }
    }

    if (f == 1) {
      for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
          if (m[i][j] != m[n - 1 - i][n - 1 - j]) {
            f = 0;
            break;
          }
        }
      }
    }

    if (f == 0)
      printf("Test #%d: Non-symmetric.\n", c);
    else
      printf("Test #%d: Symmetric.\n", c);

    c++;
  }

  return 0;
}
