#include<iostream>
using namespace std;

int main(){
    long long table[51];
    table[0] = table[1] = 1;
    for(int i = 2; i < 51; i++) table[i] = table[i - 1] + table[i - 2];

    int n;
    while(cin >> n){
        if(n == 0) break;
        cout << table[n] << endl;
    }
}