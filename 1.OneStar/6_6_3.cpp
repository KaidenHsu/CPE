#include <iostream>
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  while (n--) {
    int tr[100] = {}, cnt = 0, L;
    cin >> L;

    for(int i = 0; i <= L - 1; i++) cin >> tr[i];

    for(int i = 0; i <= L - 2; i++){
      for(int k = 0; k <= (L - i - 2); k++){
        if(tr[k] > tr[k + 1]){
          swap(tr[k], tr[k + 1]);
          cnt++;
        }
      }
    }

    cout << "Optimal train swapping takes " << cnt << " swaps." << endl;
  }

  return 0;
}
