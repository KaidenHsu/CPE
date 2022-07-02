#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int n;

    while(cin >> n && n){
        //Store the node connections data in nbs[]
        int *nbs = new int[n * n];
        #define nbs(x, y) nbs[x * n + y]
        for(int i = 0; i < n * n; i++) nbs[i] = 0; //0: not connected 1: connected

        int m;
        cin >> m;
        while(m--){
            int x, y;
            cin >> x >> y;

            nbs(x, y) = nbs(y, x) = 1;
        }

        vector<int> clr(n); //0: not colored, 1: colored
        clr[0] = 1;
        stack<int> stk;
        stk. push(0);
        bool ans = true;

        while(stk.size()){
            int a = stk.top();
            stk.pop();

            for(int k = 0; k < n; k++){
                if(!nbs(a, k)) continue; //continue if node a and node k isn't connected

                if(clr[k] == 0){ //if node k isn't colored
                    clr[k] = -clr[a];
                    stk.push(k);
                }else if(clr[k] == clr[a]){ //if two adjacent nodes have the same color
                    ans = false;
                    break;
                }
            }

            if(ans == false) break;
        }

        delete [] nbs;
        
        if(ans) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
}