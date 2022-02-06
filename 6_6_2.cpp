#include <iostream>
#include <cstring>
using namespace std;

int main(){
  string s = "";
  while (getline(cin, s)) {
    int arr[300] = {};
    for (int i = 0; i < s.size(); i++) {
      arr[s.at(i)]++;
    }

    for (int i = 1; i <=s.size() ; i++) {
      for (int j = sizeof(arr) / sizeof(arr[0]); j >=0; j--) {
        if (arr[j] == i) {
          cout << j << " " << i << endl;
        }
      }
    }
    cout << endl;
  }
}
