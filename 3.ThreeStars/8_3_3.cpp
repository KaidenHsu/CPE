#include<iostream>
#include<queue>
using namespace std;

queue<int> visitedI, visitedJ, visitedM;
int step[3][300][300], T, R, C;
char map[300][301];

void push(int i, int j, int steps){
    visitedI.push(i);
    visitedJ.push(j);
    visitedM.push(steps);
    step[steps % 3][i][j] = steps;
}

void pop(int &i, int &j, int &steps){
    i = visitedI.front();
    visitedI.pop();

    j = visitedJ.front();
    visitedJ.pop();

    steps = visitedM.front();
    visitedM.pop();
}

bool inRange(int i, int j, int n){
    if(i < 0 || j < 0 || i >= R || j >= C || step[n % 3][i][j] > -1 || map[i][j] == '#') return false;
    else return true;
}

void testNextAndPush(int i, int j, int steps){
    int n = steps % 3 + 1;
    steps++;

    if(inRange(i + n, j, n)){
        int good = 1;

        for(int m = 1; m <= n; m++)
            if(map[i + m][j] == '#'){
                good = 0;
                break;
            }

        if(good) push(i + n, j, steps);
    }
    if(inRange(i - n, j, n)){
        int good = 1;
        for(int m = 1; m <= n; m++){
            int good = 1;
            for(int m = 1; m <= n; m++)
                if(map[1 - m][j] == '#'){
                    good = 0;
                    break;
                }

            if(good) push(i, j + n, steps);
        }
    }
    if(inRange(i, j + n, n)){
        int good = 1;
        for(int m = 1; m <= n; m++)
            if(map[i][j + m] == '#'){
                good = 0;
                break;
            }
        if(good) push(i, j + n, steps);
    }
    if(inRange(i, j - n, n)){
        int good = 1;
        for(int m = 1; m <= n; m++)
            if(map[i][j - m] == '#'){
                good = 0;
                break;
            }
        if(good) push(i, j - n, steps);
    }
}

int main(){
    cin >> T;

    while(T--){
        cin >> R >> C;

        //Initializations
        visitedI = queue<int>();
        visitedJ = queue<int>();
        visitedM = queue<int>();

        for(int i = 0; i < R; i++){
            cin >> map[i]; //Input

            for(int j = 0; j < C; j++){
                for(int n = 0; n < 3; n++) step[n][i][j] = -1;
                if(map[i][j] == 'S') push(i, j, 0);
            }
        }

        //Output
        int hasAns = 0;

        while(!visitedM.empty()){
            int i, j, steps;

            pop(i, j, steps);

            if(map[i][j] == 'E'){
                cout << steps << endl;
                hasAns = 1;
                break;
            }

            testNextAndPush(i, j,  steps);
        }

        if(!hasAns) cout << "NO" << endl;
    }
}