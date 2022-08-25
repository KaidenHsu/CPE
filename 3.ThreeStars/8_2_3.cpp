#include<iostream>
#include<iomanip>
using namespace std;

const int MAX = 300 * 10 + 1, NUM_COIN = 11;

long long ans[MAX];
int coin[NUM_COIN] = {0, 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

int main(){
    //Initialization
    for(int i = 0; i < MAX; i++) ans[i] = 1;

    //Dynamic Programming
    for(int i = 1; i < NUM_COIN; i++)
        for(int j = coin[i]; j < MAX; j++)
            ans[j] += ans[j - coin[i]]; //A(k, m) = A(k-1, m) + A(k, m - C(k))

    //Input and Output
    double x;
    cout << fixed << setprecision(2);

    while(cin >> x && x != 0.00){
        cout << setw(6) << x << setw(17) << ans[int(x * 10.0)] << endl;
    }
}