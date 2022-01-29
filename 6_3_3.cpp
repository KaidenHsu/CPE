#include <iostream>
using namespace std;

int main(void)
{
  int N, m, v, b1, b2;
  cin >> N;

  while (N--) {
    cin >> m;
    b1 = 0;
    b2 = 0;

    for(v = m ; v ; v /= 2) b1 += v % 2;

    for(; m ; m /= 10)
      for(v = m % 10 ; v ; v /= 2)
        b2 += v % 2;

    cout << b1 << " " << b2 << endl;
  }
  return 0;
}
