#include <stdio.h>
#include <string.h>

int main(void)
{
  char cp_ch, instruction[101], map[51][51], direct[4] = {'E', 'S', 'W', 'N'}, *ptr;
  int op_x[4] = {1, 0, -1, 0}, op_y[4] = {0, -1, 0, 1}, bound_top, bound_right, cp_x, cp_y, cp_direct, np_x, np_y;

  scanf("%d%d", &bound_right, &bound_top);
  for(cp_y = 0; cp_y <= bound_top; cp_y++){
    for(cp_x = 0; cp_x <= bound_right; cp_x++) map[cp_y][cp_x] = 0;
  }

  while (scanf("%d %d %c", &cp_x, &cp_y, &cp_ch) != EOF) {
    for(cp_direct = 0; cp_direct < 4; cp_direct++)
      if (cp_ch == direct[cp_direct]) break;

    scanf("%s", instruction);
    for(ptr = instruction; *ptr != '\0'; ++ptr){
      if('F' == *ptr){
        np_x = cp_x + op_x[cp_direct];
        np_y = cp_y + op_y[cp_direct];

        if(np_x < 0 || np_x > bound_right || np_y < 0 || np_y > bound_top){
          if (0 == map[cp_y][cp_x]) {
            printf("%d %d %c LOST\n", cp_x, cp_y, direct[cp_direct]);
            map[cp_y][cp_x] = 'Q';
            break;
          }
        }else{
          cp_x = np_x;
          cp_y = np_y;
        }
      }else if ('R' == *ptr) {
        cp_direct++;
        if (cp_direct >= 4) cp_direct = 0;
      }else if ('L' == *ptr) {
        cp_direct--;
        if (cp_direct < 0) cp_direct = 3;
      }
    }

    if ('\0' == *ptr) printf("%d %d %c\n", cp_x, cp_y, direct[cp_direct]);
  }

  return 0;
}
