#include <iostream>
using namespace std;

int fib[5001][1500], digit[5001];

int main(void)
{
  int i, j, n;
  fib[0][0] = 0;
  fib[1][0] = 1;

  for (i = 2; i < 5001; i++) {
    for (j = 0; j < 1500; j++) {
      fib[i][j] += fib[i - 1][j] + fib[i - 2][j];

      if (fib[i][j] >= 10) {
        fib[i][j + 1] += fib[i][j] / 10;
        fib[i][j] %= 10;
      }
    }

    for(j = 1500; fib[i][j] == 0; j--) digit[i] = j;
  }

  while (cin >> n) {
    cout << "The Fibonacci number for " << n << " is ";
    for(i = digit[n] - 1; i >= 0; --i) cout << fib[n][i];
    cout << endl;
  }

  return 0;
}
