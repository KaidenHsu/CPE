#include <iostream>
using namespace std;

int main(void)
{
  bool preone;
  int k, m, n, f[40] = {0 , 1};

  for (k = 2; k < 40; ++k) {
    f[k] = f[k - 1] + f[k - 2];
  }

  cin >> n;
  while (n--) {
    cin >> m;
    cout << m << "=";
    preone = false;

    for (int k = 39; k >= 2; k--) {
      if (m >= f[k]) {
        cout << "1";
        m -= f[k];
        preone = true;
      }else if (preone) {
        cout << "0";
      }
    }
    cout << " (fib)" << endl;
  }
  return 0;
}
