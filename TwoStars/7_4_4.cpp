#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b, int *x, int *y){
  int tx, ty, d;

  if (b > a) {
    return gcd(b, a, x, y);
  }

  if (b == 0) {
    *x = 1;
    *y = 0;
    return a;
  }

  d = gcd(b, a % b, &tx, &ty);
  *x = ty;
  *y = tx - floor(a / b) * ty;

  return d;
}

int main(void)
{
  int a, b, x, y, d;

  while (cin >> a >> b) {
    d = gcd(a, b, &x, &y);
    cout << x << " " << y << " " << d << endl;
  }

  return 0;
}
