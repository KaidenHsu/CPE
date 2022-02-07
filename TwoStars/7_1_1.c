#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[100001];
  int i, j, k, len, flag;

  while(scanf("%s",s)!=EOF){
    if(strcmp(s, ".") == 0)
      break;

    len = strlen(s);
    flag = 0;

    for(i = 1 ; i <= len ; i++){
      if(len % i != 0)
        continue;

      flag = 1;

      for(j = i ; j < len && flag == 1 ; j += i){
        for(k = 0 ; k < i && flag == 1 ; k++){
          if(s[k] != s[j + k])
            flag = 0;
        }
      }

      if(flag){
        printf("%d\n", len/i);
        break;
      }
    }
  }

return 0;
}
