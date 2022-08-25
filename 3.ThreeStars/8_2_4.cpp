#include<iostream>
using namespace std;

int main(){
    int p[11], n, dataset = 0;
    //Initialization
    p[0] = 1;
    p[1] = 1;

    for(int i= 2; i <= 10; i++){
        p[i] = 0; //Initialization

        for(int j = 0; j < i; j++) p[i] += p[j] * p[i - j - 1]; //Dynamic Programming
    }

    while(cin >> n){
        if(dataset > 1) cout << endl;
        cout << p[n] << endl;
        dataset++;
    }
}