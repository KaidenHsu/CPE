#include<iostream>
#include<climits>
using namespace std;
#define SIZE 1000

int selector(int iq[], int weight[], int from, int count){ //select the elephant which has the greatest IQ (if two elephants have the same IQ, the one with smallest weight is selected)
    int indextmp = 0, iqtmp = INT_MIN, weighttmp = INT_MAX;

    for(int i = from; i < count; i++){
        if(iq[i] > iqtmp){
            iqtmp = iq[i];
            weighttmp = weight[i];
            indextmp = i;
        }else if(iq[i] == iqtmp){
            if(weight[i] < weighttmp){
                weighttmp = weight[i];
                indextmp = i;
            }
        }
    }

    return indextmp;
}

void sortByIQWeight(int iq[], int weight[], int id[], int count){
    int swapIndex;

    for(int i = 0; i < count; i++){ //Selection Sort
        swapIndex = selector(iq, weight, i, count);
        swap(iq[i], iq[swapIndex]);
        swap(weight[i], weight[swapIndex]);
        swap(id[i], id[swapIndex]);
    }
}

int LIS(int iq[], int weight[], int pre[], int len[], int count){
    int maxLength = 0, maxLengthIndex = -1;

    for(int i = 0; i < count; i++) //Dynamic Programming
        for(int j = 0; j < i; j++)
            if(weight[i] > weight[j] && len[i] <= len[j]){
                pre[i] = j;
                len[i] = len[j] + 1;

                if(maxLength < len[i]){
                    maxLength = len[i];
                    maxLengthIndex = i;
                }
            }

    return maxLengthIndex;
}

void printLISid(int id[], int pre[], int len[], int LISmaxLengthIndex){
    int *resultID = new int[len[LISmaxLengthIndex]], indextmp = LISmaxLengthIndex;

    cout << endl << len[LISmaxLengthIndex] << endl;

    for(int i = len[LISmaxLengthIndex] - 1; i >= 0; i--){
        resultID[i] = id[indextmp];
        indextmp = pre[indextmp];
    }

    for(int i = 0; i < len[LISmaxLengthIndex]; i++) cout << resultID[i] << endl;

    delete [] resultID;
}

int main(){
    int weight[SIZE] = {0}, iq[SIZE] = {0}, id[SIZE] = {0}, pre[SIZE], len[SIZE], count = 0, LISlastIndex = -1;
    for(int i = 0; i < SIZE; i++) pre[i] = -1;
    for(int i = 0; i < SIZE; i++) len[i] = 1;

    while(cin >> weight[count] >> iq[count]){
        id[count] = count + 1;
        count++;
    }

    sortByIQWeight(iq, weight, id, count);
    LISlastIndex = LIS(iq, weight, pre, len, count);
    for(int i = 0; i < count; i++) cout << pre[i] << endl;
    printLISid(id, pre, len, LISlastIndex);
}