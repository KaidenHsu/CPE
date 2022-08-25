#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
  int n, k, rsd;
  string num, b = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    while (cin >> num) {
      for (k = 0; k < num.size(); ++k){
        num[k] = b.find(num[k]);
        num[k]  = max(0, (int)num[k]);
      }

      n = *max_element(num.begin(), num.end()) + 1;
      n = max(n, 2);

      for(; n <= 62 ; n++){
         rsd = 0;

        for (k = 0; k < num.size(); ++k) {
          rsd = rsd * n + num [k];
          rsd %= (n - 1);
        }

        if (rsd == 0) break;
      }

      if (n <= 62)  cout << n;
      else cout << "such number is impossible!";
      cout << endl;
    }

  return 0;
}
