#include <iostream>
using namespace std;

int h[100];
int main(void)
{
  int T, N, P;
  cin >> T;
  int day[3651];

  while (T--) {
    cin >> N >> P;

    for (int i = 0; i <= 3650; i++) day[i] = 0;

    for (int i = 0; i < P; i++) {
      cin >> h[i];
      for (int j = h[i]; j <= N; j += h[i]) {
        day[j] = 1;
      }
    }

    int count = 0;
    for (int j = 1; j <= N; j++) {
      if (j % 7 == 6 || j % 7 ==0) continue;
      if (day[j] == 1) count++;
    }

    cout << count << endl;
  }

  return 0;
}
