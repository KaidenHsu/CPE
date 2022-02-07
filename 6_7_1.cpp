#include <iostream>
using namespace std;

int n, m, field = 0, ans[100][100];
char line[100][101];

void input(){
  for(int i = 0; i < n; i++){
    cin >> line[i];

    for(int j = 0; j < m; j++){
      ans[i][j] = 0;
    }
  }
}

void MineAddNeighbourOne(int i, int j){
  for(int ii = i - 1; ii <= i + 1; ii++){
    for(int jj = j - 1; jj <= j + 1; jj++){
      if(ii < 0 || ii >= n || jj < 0 || jj >= m) continue;

      ans[ii][jj]++;
    }
  }
}

void output(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(line[i][j] == '*') MineAddNeighbourOne(i, j);
    }
  }

  if (field > 1) cout << endl;
  cout << "Field#" << field << ":" << endl;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(line[i][j] == '*') cout << "*";
      else cout << ans[i][j];
    }
    cout << endl;
  }
}

int main(void)
{
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;

    input();
    field++;
    output();
  }

  return 0;
}
