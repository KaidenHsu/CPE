#include<iostream>
using namespace std;

int DigitSum(int n){
    int sum = 0;
    while(n > 0){
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int FactorDigitSum(int n){
    int sum = 0, tmp = n;

    for(int i = 2; i * i <= tmp; i++){
        while(tmp % i == 0){
            tmp /= i;
            sum +=DigitSum(i);
        }
    }

    if(n != tmp){ //if n is a composite number
        if(tmp != 1) sum += DigitSum(tmp);
        return sum;
    }else return 0;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int ans = n + 1;

        while(true){
            if(DigitSum(ans) == FactorDigitSum(ans)) break;
            else ++ans;
        }

        cout << ans << endl;
    }
}