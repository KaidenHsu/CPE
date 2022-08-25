#include <iostream>
using namespace std;

int main(void)
{
  char c, k = 0;

  while(cin.get(c)){
    if(c != '"')
      cout << c;
    else if(++k % 2)
      cout << "``";
    else
      cout << "''";
  }

  return 0;
}
