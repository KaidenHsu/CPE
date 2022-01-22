#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char s[100000], t[100000];
  int i,j;

  while(scanf("%s%s", &s, &t)!= EOF){
    i = 0;
    j = 0;

    for (i = 0; i < strlen(s); ++i) {
       for(; s[i] != t[j] && j < strlen(t); j++);
       if(t[j] == '\0')
         break;
       j++;
    }

    if(s[i] == '\0')
      printf("Yes\n");
    else
      printf("No\n");

  }

  return 0;
}
