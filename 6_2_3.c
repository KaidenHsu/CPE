#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int sets, num, n, i;
  double p, pi;
  scanf("%d", &sets);

  for(num = 0 ; num < sets ; num++){
    scanf("%d%lf%d", &n, &p, &i);

    if (p < 0.00001) {
      printf("0.0000\n");
    }else {
      pi = pow(1 - p, i -1) * p / (1 - pow(1 - p, n));
      /* pi = pow(double(1 - p),double(i - 1)) * p / (1 - pow(double(1 - p),double(n)); */
      printf("%.4lf\n", pi);
    }
  }

  return 0;
}
