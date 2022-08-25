#include <iostream>
#include <cctype>
using namespace std;

int main(void)
{
  int count[256] = {0}, len;
  char c;

  while(cin >> c){
    count[toupper(c)]++;
    len++;
  }

  while(len--){
    for(c = 'A'; c <= 'Z'; c++){
      if (count[c] == len) {
        cout << c << " " << count[c] << endl;
      }
    }
  }

  return 0;
}
