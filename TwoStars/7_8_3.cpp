#include<iostream>
#include<queue>
using namespace std;

bool find(int n, int m){
    queue<int> crisis;
    for(int tmp = 1; tmp <= n; tmp++) crisis.push(tmp);

    int cnt = 0;
    while(crisis.size() != 1){
        int Target = crisis.front();
        crisis.pop();
        if(cnt % m != 0) crisis.push(Target);
        cnt++;
    }
    
    return crisis.front() == 13;
}

int main(){
    int n;
    while(cin >> n && n)
        for(int m = 1;;m++)
            if(find(n, m)){
                cout << m << endl;
                break;
            }
}