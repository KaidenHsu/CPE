#include<iostream>
using namespace std;
#define sign(X) ((X) < 0? -1 : ((X) > 0? 1 : 0)) // X>0=>1, X<0=>-1, X=0=>0(the cherry is lying on the beeline)

int main(){
    int n, sx[101] , sy[101], k, diff, s;

    while(cin >> n && n){ //n isn't zero
        for(k = 0; k < 2 * n; k++) cin >> sx[k] >> sy[k];

        for(int a = -500; a <= 500; a++) //method of exhaustion (1001*1001 possibilities)
            for(int b = -500; b <= 500; b++){
                for(diff = k = 0; k < 2 * n; k++){
                    if(s = sign(a * sx[k] + b * sy[k])) diff += s;
                    else{diff = 1; break;} // the cherry is lying on the beeline
                }

                if(diff) continue;

                cout << a << " " << b << endl;
                a = b = 1000; //exit all the loops
            }
    }
}