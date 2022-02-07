#include <stdio.h>

int main(void)
{
  int v, t;

  while(scanf("%d%d", &v, &t))
    printf("%d\n", 2 * v * t);

  return 0;
}
