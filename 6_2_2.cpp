#include <iostream>
#include <set>
using namespace std;

int main(void)
{
  int n;

  while(cin >> n){
    set<int> tank;
    int i, a;
    cin >> a;

    for (i = 1; i < n; ++i) {
      int b;
      cin >> b;

      int d = (b - a < 0 ?a - b : b - a);

      if(d && d < n)
        tank.insert(d);

      a = b;
    }
    if(tank.size() == n - 1)
      cout << "Jolly";
    else
      cout << "Not jolly";

    cout << endl;
  }

  return 0;
}
