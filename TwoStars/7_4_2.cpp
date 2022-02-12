#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

int gcd(int i, int j){
  while(j) swap(i %= j, j);
  return i;
}

int main(void)
{
  string s;
  while (cin >> s, s != "0") {
    s = s.substr(0, s.size() - 3).substr(2);
    int num, den = INT_MAX, n = s.size();

    for(int k = 1; k <= n; k++){
      int u = atoi(s.c_str()) - atoi(s.substr(0, n - k).c_str());
      int d = pow(10, n) - pow(10, n - k);
      int g = gcd(u, d); u /= g; d /= g;
      if (d < den) den = d, num = u;
    }

    cout << num << "/" << den << endl;
  }

  return 0;
}
