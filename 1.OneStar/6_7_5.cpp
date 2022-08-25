#include <iostream>
using namespace std;

int main(void)
{
  int n, sum = 0, surplus = 0;

  while (cin >> n) {
    sum = n;

    while (n >= 3) {
      surplus = n % 3;
      n /= 3;
      sum += n;
      n += surplus;
    }

    if (n == 2) sum++;
    cout << sum << endl;
  }
  return 0;
}
