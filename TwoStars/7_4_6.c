#include<stdio.h>
#include<string.h>

int isprime(int p){
    for(int i = 2; i * i <= p; i++)
        if(p % i == 0) return 0;
    
    return 1;
}

int main(){
    int a, b;
    char t[10000]; //memoization
    memset(t, 0, sizeof(t));

    while(scanf("%d %d", &a, &b) != EOF){
        int count = 0;

        for(int i = a; i <= b; i++){
            if(t[i] == 0){ //hasn't been compute before
                int num = i * i + i + 41;

                if(isprime(num)){
                    t[i] = 1; //prime
                    count++;
                }else t[i] = 2; //not prime
            }else if(t[i] == 1) count++;
        }

        printf("%.2lf\n", ((double)count / (b - a + 1) * 100) + 0.00001);
    }
}