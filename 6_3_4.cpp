#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
  stack<int> st;
  int n, parity;

  while (cin >> n && n) {
    parity = 0;
    while (n) {
      st.push(n % 2);
      parity += n % 2;
      n /= 2;
    }

    cout << "The parity of ";
    while (st.size()) {
      cout << st.top();
      st.pop();
    }
    cout << " is " << parity << " (mod2)." << endl;
  }
  return 0;
}
