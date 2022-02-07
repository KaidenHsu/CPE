#include <stdio.h>

int main(void)
{
  int T, i, M, N, Q, r, c, ans, a, b, flag;
  char map[101][101];

  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d", &M, &N, &Q);

    for (i = 0; i < M; ++i)
      scanf("%s", map[i]);

    printf("\n%d %d %d\n", M, N, Q);

    while (Q--) {
      scanf("%d %d", &r, &c);

      ans = 1;

      for(i = 1; i <= M && i <= N; i++){
        flag = 0;

        for(a = r - i; a <= r + i; a++){
          for(b = c - i; b <= c + i; b++){
            if(a < 0 || b < 0 || a >= M || b >= N){
              flag = 1;
              break;
            }
            if(map[a][b] != map[r][c]){
              flag = 1;
              break;
            }
          }
        }

        if (!flag) ans += 2;
        else break;
      }
      printf("%d\n", ans);
    }
  }
}
