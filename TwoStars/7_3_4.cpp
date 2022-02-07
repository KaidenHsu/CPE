#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void)
{
  int n;
  while (cin >> n && n) {
    int arr[1000] = {}, sum = 0;

    for(int i = 0; i < n; i++){
      int x, y;
      scanf("%d.%d", &x, &y);
      arr[i] = 100 * x + y;
      sum += arr[i];
    }

    double avg = (double)sum / (double)n, diff1 = 0, diff2 = 0;

    for(int i = 0; i < n; i++){
      if(avg > arr[i]) diff1 += floor(avg - arr[i]);
      else diff2 += floor(arr[i] - avg);
    }

    if (diff1 > diff2) printf("$%.2lf\n", diff1 / 100);
    else printf("$%.2lf\n", diff2 / 100);
  }

  return 0;
}
