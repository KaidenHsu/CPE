#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
  char octave[] = "XcdefgabCDEFGAB", finger[16][11] = {"0000000000", "0111001111", "0111001110", "0111001100", "0111001000", "0111000000", "0110000000", "0100000000", "0010000000", "1111001110", "1111001100", "1111001000", "1111000000", "1110000000", "1100000000"};

  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    char str[300];
    cin.getline(str, 300);
    int len = strlen(str), cnt[10] = {}, cur = 0, next;

    for(int i = 0; i < len; i++){
      for(next = 1; octave[next] != str[i]; next++);

      for(int j = 0; j < 10; j++)
        if (finger[cur][j] == '0' && finger[next][j] == '1') cnt[j]++;

      cur = next;
    }

    cout << cnt[0];
    for(int j = 1; j < 10; j++) cout << " " << cnt[j];
    cout << endl;
  }

  return 0;
}
