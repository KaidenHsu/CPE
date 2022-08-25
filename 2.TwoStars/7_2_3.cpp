#include <iostream>
using namespace std;

int main(void)
{
  int i, j, n, ans[1001], pd[3000] = {1};

  for (i = 1; i <= 1000; ++i) {
    for (j = 0; j < 3000; ++j) pd[j] *= i;

    for (j = 0; j < 3000; ++j) {
      pd[j + 1] += pd[j] / 10;
      pd[j] %= 10;
    }

    for (j = 0; j < 3000; ++j) ans[i] += pd[j];
  }

  while(cin >> n) cout << ans[n] << endl;

  return 0;
}
