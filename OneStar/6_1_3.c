#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char n[11];

  while(scanf("%s", n) != EOF && n[0] != 48){
    while(strlen(n) != 1){
      int i = 0, F = 0;
      for(i = 0 ; i < strlen(n) ; i++)
        F += (n[i] -48);
      memset(n,'\0', 11);
      sprintf(n, "%d",F);
    }
    printf("%s", n);
  }
  return 0;
}
