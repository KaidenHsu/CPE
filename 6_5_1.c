#include <stdio.h>

int main(void)
{
  int T, M, N, Q, r, c, i, a, b, ans, flag;
  char map[101][101];

  scanf("%d", &T);

  while (T--) {
    scanf("%d %d %d", &M, &N, &Q);

    for(i = 0; i < M; i++)
      scanf("%s", map[i]);

    printf("\n%d %d %d\n", M, N, Q);

    while (Q--) {
      ans = 1;

      scanf("%d %d", &r, &c);

      for (i = 0; i <= M || i <= N; ++i) {
        flag = 0;

        for(a = r - i; a <= r + i; a++){
          for(b = c - i; b <= c + i; b++){
            if (a < 0 || b < 0 || a >= M || b >= N) {
              flag = 1;
              break;
            }

            if (map[a][b] != map[r][c]) {
              flag = 1;
              break;
            }
          }
        }

        if (!flag) ans += 2;
        else break;
      }

      printf("%d\n", ans - 2);
    }
  }

  return 0;
}
