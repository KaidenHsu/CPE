#include<iostream>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int len, n;
        cin >> len >> n;

        int m = -100, M = -100;
        for(int i = 0; i < n; i++){
            int loc;
            cin >> loc;

            m = max(m, min(loc, len - loc));
            M = max(M, max(loc, len - loc));
        }

        cout << m << " " << M << endl;
    }
}