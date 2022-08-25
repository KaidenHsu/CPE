#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class BigNum{
  private:
    vector<int> _number;

  public:
    BigNum(const string &number){
      for(int i = number.length() - 1 ; i >= 0 ; --i)
        _number.push_back(number[i] - '0');
    }

    BigNum(const vector<int> &number){
      _number = number;
    }

    BigNum add(const BigNum &bigNum){
      vector<int> result;
      int carry = 0, maxDigit = max(_number.size(), bigNum._number.size());

      for(int index = 0 ; index < maxDigit ; ++index){
        int sum = carry;

        if(index < _number.size()) sum += _number[index];
        if(index < bigNum._number.size()) sum += bigNum._number[index];

        result.push_back(sum % 10);
        carry = sum / 10;
      }

      if(carry > 0) result.push_back(carry);

      return BigNum(result);
    }

    int compareTo(const BigNum &bigNum){
      if(_number.size() > bigNum._number.size()) return 1;
      if(_number.size() < bigNum._number.size()) return -1;

      for(int i = _number.size() - 1 ; i >= 0 ; --i){
        if(_number[i] > bigNum._number[i]) return 1;
        if(_number[i] < bigNum._number[i]) return -1;
      }

      return 0;
    }

    int getSize(){
      return _number.size();
    }
};

int main(){
  //Memoization
  vector<BigNum> memorize;
  memorize.push_back(BigNum("1"));
  memorize.push_back(BigNum("2"));
  BigNum nextItem("0");

  do{
    nextItem = memorize[memorize.size() - 1].add(memorize[memorize.size() - 2]);
    memorize.push_back(nextItem);
  } while(nextItem.getSize() <= 100);

  //Input
  const BigNum ZERO("0");
  string a, b;

  while(cin >> a >> b){
    BigNum aNum(a), bNum(b);
    if(aNum.compareTo(ZERO) == 0 && bNum.compareTo(ZERO) == 0) break;

    //Output
    int total = 0;

    for(int i = 0 ; i < memorize.size() ; ++i){
      int compareA = aNum.compareTo(memorize[i]);
      int compareB = bNum.compareTo(memorize[i]);

      if(compareB < 0) break;
      if(compareA <= 0 && compareB >= 0) total++;
    }

    cout << total << endl;
  }
}