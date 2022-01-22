#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(void)
{
  char c, s[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

  while(cin.get(c)){
    c = tolower(c);
    char *p = strchr(s,c);

    if (p) {
      cout << *(p - 2);
    }else{
      cout << c;
    }
  }

  return 0;
}
