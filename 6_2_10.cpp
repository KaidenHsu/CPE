#include <iostream>
using namespace std;

int main(void)
{
  int b[1005] = {}, n, t = 0, num, i, j;
  while (cin >> n) {
    int b2 = 0;
    for (i = 1; i <=  n; ++i) {
      cin >> b[i];
      if (b[i] <= b[i - 1] ) b2 = 1;
    }

    int note[20005] = {};

    if(b2 == 0)
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

          if (i == j) num = 1;
          else num =2;

          if(note[b[i] + b[j]] == num){
            b2 = 1;
            goto MARK;
          }

          note[b[i] + b[j]]++;
        }
      }

MARK:
    cout << "Case#" << ++t << ": It is ";
    if (!b2) cout << "a B2-Sequence." << endl << endl ;
    else cout << "not a B2-Sequence." << endl << endl ;
  }
}
