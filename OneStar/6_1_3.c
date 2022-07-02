#include <stdio.h>
#include <string.h>

int main()
{
  char n[11];

  while(scanf("%s", n) != EOF && n[0] != '0'){
    while(strlen(n) != 1){
      int F = 0;
      for(int i = 0 ; i < strlen(n) ; i++) F += (n[i] - '0');
      memset(n,'\0', 11);
      sprintf(n, "%d", F); //int -> string
    }

    printf("%s\n", n);
  }
}