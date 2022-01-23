#include <iostream>
using namespace std;

int main(void)
{
  char week[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  int i, n, month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  cin >> n;

  while(n--){
    int w = 5, month, day;
    cin >> month >> day;

    for (i = 1; i < month; ++i)
      w += month_days[i - 1];

    w = (w + day) % 7;

    cout << week[w] << endl;

  }
  return 0;
}
