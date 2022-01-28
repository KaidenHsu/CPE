#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string operator*(string& a, string& b){
  int k, h;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  for (k = 0; k < a.size(); ++k) a[k] -= '0';
  for (k = 0; k < b.size(); ++k) b[k] -= '0';

  string c(a.size() + b.size(), 0);

  for (k = 0; k < a.size(); ++k) {
    for (h = 0; h < b.size(); ++h)
      c[k + h] += a[k] * b[h];

    for (h = 0; h < c.size(); ++h) {
      if (h + 1 < c.size()) c[h + 1] += c[h] / 10;
      c[h] %= 10;
    }
  }

  int n = c.size();
  while(n && c[n - 1] == 0) n--;
  c.resize(n);

  for(k = 0 ;  k < c.size() ; k++) c[k] +='0';
  if (c.size() == 0) c = "0";
  reverse(c.begin(), c.end());

  return c;
}

int main(void)
{
  string a, b;

  while(cin >> a >> b) cout << a * b << endl;

  return 0;
}
