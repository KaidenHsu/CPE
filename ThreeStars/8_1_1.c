#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 30000000


//global variables
long long primes[2000000];
int pcount = 1;


void setprimes(){
    //declaration
    char n[MAX] = {};

    //sieve of eratosthenes
    for(int i = 3; i < sqrt(MAX); i += 2)
        if(n[i] == 0) // if this number is a prime number
            for(int j = i * i; j < MAX; j += (2 * i)) n[j] = '1'; //keep this number and eliminate all its multiple

    //generate the prime number list
    primes[0] = 2;
    for(int i = 3; i < MAX; i+= 2)
        if(n[i] == 0) primes[pcount++] = i;
}


int main(){
    //declaration
    long long n;

    setprimes();

    while(scanf("%lld", &n) != EOF){
        if(n == 0){
            printf("1\n");
        }else{
            int count, ans = 1;

            while(n % 2 == 0) n /= 2;

            for(int i = 1; i < pcount; i++){

                if(primes[i] * primes[i] > n) break;

                count = 0;
                while(n % primes[i] == 0){
                    n /= primes[i];
                    count++;
                }

                ans *= (count + 1);
            }

            if(n != 1) ans *= 2;

            printf("%d\n", ans);
        }
    }
}