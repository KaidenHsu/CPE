#include<stdio.h>
#include<stdbool.h>

int m, n;
char Map[100][100];
bool Collected[100][100];

void CollectOil(int i, int j){
    if(i < 0 || j < 0 || i >= m || j >= n) return; //return; in void function => jump out the function
    else if(Map[i][j] == '*' || Collected[i][j]) return;
    else{
        Collected[i][j] = true;
        //Recursion
        CollectOil(i - 1, j - 1);
        CollectOil(i - 1, j);
        CollectOil(i - 1, j + 1);
        CollectOil(i, j - 1);
        CollectOil(i, j + 1);
        CollectOil(i + 1, j - 1);
        CollectOil(i + 1, j);
        CollectOil(i + 1, j);
        CollectOil(i + 1, j + 1);
    }
}

int main(){
    //Read the first test case
    scanf("%d %d", &m, &n);

    while(m != 0 || n != 0){ //n and m isn't both 0
        //Initialization
        for(int i = 0; i < m; i++) scanf("%s", &Map[i]);

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                Collected[i][j] = false; //Initialize the Collected[][]

        int Num = 0;

        //DFS
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(Map[i][j] == '@' && !(Collected[i][j])){
                    Num++;
                    CollectOil(i, j);
                }

        //Output
        printf("%d\n", Num);
        
        //Read the next test case
        scanf("%d %d", &m, &n);
    }
}