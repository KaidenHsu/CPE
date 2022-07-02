#include<iostream>
using namespace std;

int main(){
    int answer[32] = {0}, len = 0;
    unsigned int T, N;
    cin >> T;

    while(T--){
        cin >> N;

        if(N == 0){
            cout << 10 << endl;
            continue;
        }else if(N == 1){
            cout << 1 << endl;
            continue;
        }

        for(int d = 9; d >= 2; d--){
            while(N % d == 0){
                N /= d;
                answer[len] = d;
                len++;
            }
        }

        if(N == 1) {
            for(int i = len - 1; i >= 0; i--) cout << answer[i];
            cout << endl;
        }else cout << -1 << endl;
    }
}