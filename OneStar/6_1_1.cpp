#include <iostream>
#include <ctype.h>
using namespace std;

int main(void)
{
  int count[1000] = {0}, length;
  char c;

  while(cin >> c){
    count[toupper(c)]++;
    length++;
  }

  while(length--){
    for(c = 'A'; c <= 'Z'; c++){
      if (count[c] == length) {
        cout << c << " " << count[c] << endl;
      }
    }
  }

  return 0;
}
