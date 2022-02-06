#include <iostream>
using namespace std;

int main(void)
{
  char str[999];
  while (cin.getline(str, 999)) {
    int arr[300] = {},;

    for(int i = 0; i < 999; i++){
       arr[i]++;
       n++
    }

    for(int i = 1; i <= 999; i++){
      for(int j = 300; j >= 0; j--){
        if (arr[j] == i) cout << j << " " << i;
      }
    }
  }

  return 0;
}
