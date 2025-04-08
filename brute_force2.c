#include<stdio.h>
#include<stdlib.h>

void knapsack(int weights[], int values[], int capacity, int len){
    int i,j,maxValue=0,bestSubset,subsetCount=1<<len;
    int tempValueSum,tempCapacitySum;
    for(i=0;i<=subsetCount;i++){
        tempCapacitySum=0;
        tempValueSum=0;
        for (j=0;j<len;j++){
            if(i & (1<<j)){
                tempValueSum+=values[j];
                tempCapacitySum+=weights[j];
            }
        }
        if (capacity >= tempCapacitySum){
            if (maxValue < tempValueSum){
                maxValue = tempValueSum;
                bestSubset = i;
            }
        }
    }
    printf("Required Result :\n");
    for(j=0;j<len;j++){
        if(bestSubset & (1<<j)){
            printf("value: %d\t weight: %d\n",values[j],weights[j]);
        }
    }
}

int knapsackRecursion(int weights[], int values[], int capacity, int len, int index){
    if (index == len || capacity ==0){
        return 0;
    }
    if(weights[index]>capacity){
        return knapsackRecursion(weights,values,capacity,len,index+1);
    }

    int take = values[index] + knapsackRecursion(weights,values,capacity-weights[index],len,index+1);
    int skip = knapsackRecursion(weights,values,capacity,len,index+1);
    return (take>skip)?take:skip;

}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int perm[],int start,int len){
    if(start==len){
        return;
    }
    for(int i=start;i<len;i++){
        swap(&perm[start],&perm[i]);
        permute(perm,start+1,len);
        swap(&perm[start],&perm[i]);
    }
}

int calculateCost(int arr[][3],int perm[],int len){
    int totalCost=0;
    for(int i=0;i<len;i++){
        totalCost+=arr[i][perm[i]];
    }
    return totalCost;
}   

void findMinCost(int arr[][3],int perm[],int l, int r, int *minCost, int bestPerm[],int len){
    if(l==r){
        int currentCost = calculateCost(arr,perm,len);
        if( currentCost < *minCost){
            *minCost = currentCost;
            for(int i=0;i<len;i++){
                bestPerm[i]=perm[i];
            }
        }
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(&perm[l], &perm[i]);
        findMinCost(arr, perm, l + 1, r, minCost, bestPerm,3);
        swap(&perm[l], &perm[i]); // backtrack
    }
}

int main(){
    //knapsack main codes
    // int weights[] = {1, 3, 4, 5, 2};
    // int values[]  = {1, 4, 5, 7, 3};
    // int capacity = 7;
    // int n = 5;
    // knapsack(weights,values,capacity,n);
    // printf("%d",knapsackRecursion(weights,values,capacity,n,0));

    //assignment problem by brute-force technique
    int n[3][3] = {{9,2,7},{6,4,3},{5,8,1}};
    int permutation[] = {0, 1, 2}; // Initial assignment
    int bestPerm[3];
    int minCost =  99999999;

    findMinCost(n, permutation, 0, 3 - 1, &minCost, bestPerm,3);

    printf("Minimum Cost: %d\n", minCost);
    printf("Best Assignment:\n");
    for (int i = 0; i < 3; i++) {
        printf("Worker %d -> Job %d\n", i, bestPerm[i]);
    }
    return 0;
}