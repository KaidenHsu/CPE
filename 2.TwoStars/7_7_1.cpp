#include<iostream>
using namespace std;
#define MX_SEG 100000

typedef struct segment{
    int left, right;
}Segment;

//Global Variables
Segment seg[MX_SEG], res[MX_SEG];
int segSize, resSize;

int CoverIt(int m){
    Segment cover = {0, m};
    resSize = 0;

    while(true){
        int max = -1;

        //Find the rightmost line segment(Greedy Algorithm)
        for(int i = 0; i < segSize; i++){
            if(seg[i].right <= cover.left || seg[i].left > cover.left) continue;
            if(max == -1 || seg[i].right > seg[max].right) max = i;
        }

        //No Solution
        if(max == -1) break;

        //Find new line segment successfully
        res[resSize++] = seg[max];
        cover.left = seg[max].right;

        if(cover.left >= cover.right) return resSize;
    }

    return resSize = 0;
}

int main(){
    int n;
    cin >> n;

    while(n--){
        int m;
        cin >> m;

        //Input
        Segment t;
        segSize = 0;

        while(cin >> t.left >> t.right){
            if(t.left == 0 && t.right == 0) break;
            seg[segSize++] = t;
        }

        //Output
        cout << CoverIt(m) << endl;
        for(int i = 0; i < resSize; i++) cout << res[i].left << " " << res[i].right << endl;
        if(n > 0) cout << endl;
    }
}