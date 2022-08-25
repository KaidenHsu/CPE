#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        //Declarations
        map<set<int>, int> count;
        int M = 0, MC = 0;

        //Compute
        while(n--){
            set<int> suit;

            for(int i = 0; i < 5; i++){
                int course;
                cin >> course;
                suit.insert(course);
            }

            count[suit]++;

            int h = count[suit];
            if(h == M) MC++;
            if(h > M){
                M = h;
                MC = 1;
            }
        }

        //Output
        cout << M * MC << endl;
    }
}