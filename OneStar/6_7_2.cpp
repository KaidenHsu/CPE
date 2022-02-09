#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str;
  int cnt, n, s, w, e, up, down, t;

  while (cin >> cnt && cnt) {
    up = 1; n = 2; w = 3; e = 4; s = 5; down = 6;

    while (cnt--) {
      cin >> str;

      if(str == "north"){
        t = up; up = s; s = down; down = n; n = t;
      }
      if(str == "south"){
        t = up; up = n; n = down; down = e; e = t;
      }
      if(str == "east"){
        t = up; up = w; w = down; down = e; e = t;
      }
      if(str == "west"){
        t = up; up = e; e = down; down = w; w = t;
      }
    }

    cout << up << endl;
  }
}
