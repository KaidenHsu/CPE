#include <iostream>
using namespace std;
char S1[31], S2[31];

int StringToInt(char S[31])
{
  int i, ans = 0;

  for (i = 0; i < 30; ++i) {
    if(S[i] == '\0') break;
    ans *= 2;
    if (S[i] == '1') ans += 1;
  }

  return ans;
}

int gcd(int p, int q){
  if(q == 0) return p;
  return gcd(q, p % q);
}

int main(void)
{
  int N;
  cin >> N;

  for (int p = 1; p <= N; p++) {
    cin >> S1 >> S2;
    int N1 = StringToInt(S1);
    int N2 = StringToInt(S2);

    if(gcd(N1, N2) > 1){
      cout << "Pair #"<< p << ": All you need is love!" << endl;
    }else {
      cout << "Pair #"<< p << ": Love is not all you need!" << endl;
    }
  }
  return 0;
}
