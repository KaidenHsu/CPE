#include <stdio.h>

int main(void)
{
  long long n, i, s, d, a, b;
  scanf("%lld", &n);

  for (i = 0; i < n; ++i) {
    scanf("%lld %lld", &s, &d);
    a = s + d;

    if (a % 2) {
      printf("impossible\n");
      continue;
    }

    a /= 2;
    b = s - a;

    if (b < 0) {
      printf("impossible\n");
      continue;
    }

    printf("%lld %lld\n", a, b);
  }

  return 0;
}
