#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
  char str[100][101];
  int i, add, j, len[100], n = 0, max = 0;

  for (i = 0; i < 100; ++i) {
    for (j = 0; j < 101; ++j) {
      str[i][j] = 0;
    len[i] = 0;
    }
  }

  while(cin.getline(str[n], 101)){
    len[n] = strlen(str[n]);
    if(len[n] > max)
      max = len[n];
    for (add = len[n]; add < max; ++add) {
      str[n][add] = ' ';
      len[n]++;
    }
    n++;
  }

  for (j = 0; j < max; ++j) {
    for(i = n - 1; i >= 0; i--)
      if(j < len[i])
        cout << str[i][j];
    cout << endl;
  }

  return 0;
}
