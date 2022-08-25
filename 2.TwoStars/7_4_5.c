#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 46341
#define TOTAL 4793

int numOfPrime = 0, checkPrime[MAX], prime[TOTAL];

void prime_filter1(){
  int i = 0, j = 0;
  prime[numOfPrime++] = 2;
  int MaxCheckValue = sqrt(MAX);

  for(i = 3; i < MaxCheckValue; i += 2){
    if (checkPrime[i - 1] == 0) prime[numOfPrime] = i;

    for(j = i * i; j < MAX; j += 2 * i) checkPrime[j - 1] = 1;
  }

  for(i = MaxCheckValue; i < MAX; i += 2)
    if (checkPrime[i - 1] ==0) prime[numOfPrime++] = i;
}

int prime_filter2(int n){
  int i = 0;

  if (n < MAX) return checkPrime[n - 1];

  for(i = 0; i < numOfPrime && i * i < n; i++)
    if (n % prime[i] == 0) return 1;

  return 0;
}

int main(void)
{
  prime_filter1();
  long int L = 0, U = 0;

  while (scanf("%ld %ld", &L, &U) != EOF) {
    long int C1 = 0, C2 = 0, D1 = 0, D2 = 0, preID = 0, max = 0, min = MAX + 1, temp[U - L + 2], i = 0, j = 0;

    if (L <= 2) {
      temp[j++] = 2;
      L = 3;
   }else if (L % 2 == 0) {
      L++;
    }

    for(i = L; i <= U; i += 2)
      if (!prime_filter2(i)) temp[j++] = i;

    for(i = 1; i < j; i++){
      long int value = temp[i] - temp[i - 1];

      if (value < min) {
        min = value;
        C1 = temp[i - 1];
        C2 = temp[i];
      }
      if (value > max) {
        max = value;
        D1 = temp[i - 1];
        D2 = temp[i];
      }
    }

    if(max == 0)
      printf("There are no adjacent primes.\n");
    else
      printf("%ld %ld are closest, %ld %ld are most distant.\n", C1, C2, D1, D2);
  }

  return 0;
}
