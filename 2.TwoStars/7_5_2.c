#include<stdio.h>
#include<math.h>
#define PI 2 * acos(0.)

int main(){
    double a;

    while(scanf("%lf", &a) == 1){
        double sq = a * a;
        double se = a * a * PI / 4;
        double bu = a * a * PI / 3 - a * a * sqrt(3) / 4;

        double x = sq - 4 * se + 4 * bu;
        double y = -sq + 3 * se - 2 * bu;
        double z = sq - 2 * se + bu;
        printf("%.3lf %.3lf %.3lf\n", x, 4 *y, 4 * z);
    }
}