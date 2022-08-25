#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define SIZE 1000

void initArr(int *ptr, int size, int InitVal){
    for(int i = 0; i < size; i++) *(ptr + i) = InitVal;
}

int selector(int *iq, int *weight, int from, int count){
    int indextmp = 0, iqtmp = INT_MIN, weighttmp = INT_MAX;

    for(int i = from; i < count; i++){
        if(*(iq + i) > iqtmp){
            iqtmp = *(iq + i);
            weighttmp = *(weight + i);
            indextmp = i;
        }else if(*(iq + i) == iqtmp){
            if(*(weight + i) < weighttmp){
                weighttmp = *(weight + i);
                indextmp = i;
            }
        }
    }

    return indextmp;
}

void swap(int *ptr, int i, int j){
    int tmp = *(ptr + j);
    *(ptr + j) = *(ptr + i);
    *(ptr + i) = tmp;
}

void sortByIQWeight(int *iq, int *weight, int *id, int count){
    int swapIndex;

    for(int i = 0; i < count; i++){ //Selection Sort
        swapIndex = selector(iq, weight, i, count);
        swap(iq, i, swapIndex);
        swap(weight, i, swapIndex);
        swap(id, i, swapIndex);
    }
}

int LIS(int *iq, int * weight, int *predecessor, int *length, int count){ //Dynamic Programming
    int maxLength = 0, maxLengthIndex = -1;

    for(int i = 0; i < count; i++){
        for(int j = 0; j < i; j++){
            if(*(weight + i) > *(weight + j) && *(length + i) <= *(length + j)){
                *(predecessor + i) = j;
                *(length + i) = *(length + j) + 1;

                if(maxLength < *(length + i)){
                    maxLength = *(length + i);
                    maxLengthIndex = i;
                }
            }
        }
    }

    return maxLengthIndex;
}

void printLISid(int *id, int *predecessor, int *length, int LISmaxLengthIndex){
    int *resultID = (int*)malloc(*(length + LISmaxLengthIndex) * sizeof(int)), indextmp = LISmaxLengthIndex;

    printf("\n%d\n", *(length + LISmaxLengthIndex));

    for(int i = *(length + LISmaxLengthIndex) - 1; i >= 0; i--){
        resultID[i] = id[indextmp];
        indextmp = predecessor[indextmp];
    }

    for(int i = 0; i < *(length + LISmaxLengthIndex); i++) printf("%d\n", resultID[i]);

    free(resultID);
}

int main(){
    int weight[SIZE], iq[SIZE], id[SIZE], predecessor[SIZE], length[SIZE], count = 0, LISlastIndex = -1;
    initArr(weight, SIZE, 0);
    initArr(iq, SIZE, 0);
    initArr(id, SIZE, 0);
    initArr(predecessor, SIZE, -1);
    initArr(length, SIZE, 1);

    while(scanf("%d%d", (weight + count), (iq + count)) != EOF){
        id[count] = count + 1;
        count++;
    }

    sortByIQWeight(iq, weight, id, count);
    LISlastIndex = LIS(iq, weight, predecessor, length, count);
    printLISid(id, predecessor, length, LISlastIndex);
}