#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
  int m, n;
  cin >> m >> n;
  map<string, int> hay;
  string s;

  while (m--) {
    int p;
    cin >> s >> p;
    hay[s] = p;
  }

  while (n--) {
    int ans = 0;
    while(cin >> s && s != ".") ans += hay[s];
    cout << ans << endl;
  }

  return 0;
}
