#include <iostream>
using namespace std;
const int MX_BASE = 36;

int main(void)
{
  int m;
  cin >> m;

  for (int k = 1; k <= m; k++) {
    cout << endl;
    cout << "Case" << k << ":" << endl;

    int coc[MX_BASE];
    for (int i = 0; i < MX_BASE; i++)
      cin >> coc[i];

    int n;
    cin >> n;

    while (n--) {
      int x;
      cin >> x;

      int cob[MX_BASE + 1];
      for (int i = 2; i <= MX_BASE; i++){
        int t = x;
        cob[i] = 0;

        do {
          cob[i] += coc[t % i];
          t /= i;
       } while (t != 0);
      }

      int min = cob[2];
      for (int i = 3; i <= MX_BASE; i++) {
        if (cob[i] < min) min = cob[i];
      }

      cout << "Cheapest Base(s) for number " << x << ":";
      for (int i = 2; i <= MX_BASE; i++)
        if (cob[i] == min) cout << " " << i;
      cout << endl;
    }

  }
return 0;
}
