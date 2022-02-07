#include <stdio.h>

int main(void)
{
  int t = 0, id = 0;
  scanf("%d", &t);

  while (id++ != t) {
    int a = 0, b = 0, n = 0, sum = 0;
    scanf("%d", &a);
    scanf("%d", &b);

    if (a % 2 == 0) a++;
    if (b % 2 == 0) b--;

    n = (b - a) / 2 + 1;
    sum = (a + b) * n / 2;

    printf("Case %d: %d\n", id, sum);

  }
    return 0;
}
