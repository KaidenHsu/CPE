#include <stdio.h>
#include <ctype.h>
#include <iostream>
using namespace std;

int main(void)
{
  int  i, n, m, runcase = 0;
  string answer, output, input;
  bool ac, pe;

  while (scanf("%d", &n) != EOF && n != 0) {
    getchar();
    answer = "", output = "";
    for (i = 0; i < n; ++i) {
      getline(cin, input);
      if(i) answer += '\n', answer += input;
      else answer = input;
    }

    scanf("%d", &m);
    getchar();
    for (i = 0; i < m; i++) {
      getline(cin, input);
        if(i) output += '\n', output += input;
        else output = input;
    }

    ac = true;
    if(output.compare(answer)) ac = false;

    if (ac) {
      printf("Run #%d: Accepted\n", ++runcase);
      continue;
    }

    for (i = 0; i < answer.length(); ++i) {
      if(!isdigit(answer[i]))
        answer.erase(i, 1), i--;
    }

    for (i = 0; i < output.length(); ++i) {
      if(!isdigit(output[i]))
        output.erase(i, 1), i--;
    }

    pe = true;
    if(answer != output) pe = false;
    if (pe) {
      printf("Run #%d: Presentation Error\n", ++runcase);
      continue;
    }

    printf("Run #%d: Wrong Answer\n", ++runcase);

  }
  return 0;
}
