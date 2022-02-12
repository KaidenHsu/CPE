#include <iostream>
using namespace std;

int gcd(int a, int b){
  while(a %= b) swap(a, b);
  return b;
}

int main(void)
{
  int v[1001];

  while (cin >> v[0], v[0]) {
    int n = 1, M = v[0], m = v[0];

    while (cin >> v[n], v[n]) {
      M = max(M, v[n]);
      m = min(m, v[n]);
      n++;
    }

    int g = M - m;
    for(int k = 0; k < n; k++) g = gcd(v[k] - m, g);

    cout << g << endl;
  }

  return 0;
}
