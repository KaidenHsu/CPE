#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 2 * acos(0.0)

int main(void)
{
  double s, a, arc, chord;
  char unit[4];
  while (scanf("%lf %lf %s", &s, &a, unit) != EOF) {
    if (strcmp(unit, "min") == 0) a /= 60;
    if (a > 180) a = 360  - a;

    arc = 2 * PI * (s + 6440) * a / 360.0;
    chord = 2 * (s + 6440) * sin(a * PI / 2 / 180);

    printf("%.6lf %.6lf\n", arc, chord);
  }
  return 0;
}
