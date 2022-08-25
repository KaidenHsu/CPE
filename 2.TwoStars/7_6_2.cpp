#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    int T, first = 1;
    cin >> T;

    while(T--){
        //input
        int m, n;
        cin >> m >> n;

        //declarations
        map<char, char> parent;
        string city1, city2;

        //m
        for(int i = 0; i < m; i++){
            cin >> city1 >> city2;
            parent[city2[0]] = city1[0];
        }

        //inserting blank lines
        if(first == 1) first = 0;
        else cout << endl;

        //n
        for(int q = 0; q < n; q++){
            //input
            cin >> city1 >> city2;

            //declarations
            char route1[26], route2[26]; //(1) 26 alphabet letters => 26 different cities at most (2)route1 => the route from city1 to Rome
            int p1 = 0, p2 = 0;

            //generate route1[] and route2[]
            route1[0] = city1[0];
            while(route1[p1] != 'R'){
                route1[p1 + 1] = parent[route1[p1]];
                p1++;
            }

            route2[0] = city2[0];
            while(route2[p2] != 'R'){
                route2[p2 + 1] = parent[route2[p2]];
                p2++;
            }

            //delete mutual parent nodes
            while(route1[p1] == route2[p2]){ //delete the mutual parent nodes
                p1--;
                p2--;
            }

            //output
            for(int i = 0; i <= p1 + 1; i++) cout << route1[i]; //city1 -> first mutual parent node

            for(int i = p2; i >= 0; i--) cout << route2[i]; //first mutual parent node -> city2

            cout << endl;
        }
    }
}