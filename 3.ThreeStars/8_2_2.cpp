#include<iostream>
using namespace std;

int main(){
    int m = 0;
    cin >> m;

    while(m--){
        //input
        int n, k, input[10001] = {0};
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> input[i];

        //declaration
        bool arr[100] = {};

        //first element
        int x = input[1] % k;
        if(x < 0) x += k;
        arr[x] = true;

        //arrTmp[] -> arr[]
        for(int i = 2; i <= n; i++){
            int arrTmp[100] = {};

            for(int j = 0; j < k; j++){
                if(arr[j]){
                    int m1 = (j + input[i]) % k;
                    if(m1 < 0) m1 += k;

                    int m2 = (j - input[i]) % k;
                    if(m2 < 0) m2 += k;

                    arrTmp[m1] = true;
                    arrTmp[m2] = true;
                }
            }

            for(int j = 0; j < k; j++) arr[j] = arrTmp[j];
        }

        // output
        if(arr[0]) cout << "Divisible" << endl;
        else cout << "Not divisible" << endl;
    }
}