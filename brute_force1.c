#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void selectionSort(int arr[], int len){
    int temp,i,j;
    for (i=0;i<len;i++){
        int minIndex = i;
        for (j=i+1;j<len;j++){
            if(arr[minIndex] > arr[j]){
                minIndex=j;
            }
        }
        if (minIndex != i){
            temp = arr[minIndex];
            arr[minIndex]=arr[i];
            arr[i]=temp;
        }
    }
}

void bubbleSort(int arr[], int len){
    int temp,i,j;
    for(j=len-1;j>0;j--){
        for (i=0;i<j;i++){
            if(arr[i] > arr[i+1]){
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void displayArr(int arr[], int len){
    for(int i=0;i<len;i++){
        printf("%d\t",arr[i]);
    }
}

int bruteStringMatching(char text[], char pattern[], int textLen, int patternLen){
    int i,j;
    for( i=0;i<=textLen - patternLen;i++){
        int temp = i;
        for(j=0;j<patternLen;j++){
            if(pattern[j]==text[temp]){
                temp++;
            } else {
                break;
            }
        }
        if(j == patternLen) {
            return 1;
        }
    }
    return 0;
}

int totalArray(int arr[], int len){
    int sum=0;
    for(int i=0;i<len;i++){
        sum+=arr[i];
    }
    return sum;
}

void partition(int arr[], int len){
    int total = totalArray(arr,len);
    int i,j,found=0,subsetSum=0;
    if(total%2!=0){
        printf("Partition not possible!!");
        return;
    }
    int subsetCount = 1<< len;
    for(i=0;i<subsetCount;i++){
        subsetSum = 0;
        for(j=0;j<len;j++){
            if(i & (1<<j)){
                subsetSum+=arr[j];
            }
        }
        if(subsetSum == total/2){
            found=1;
            printf("Partition found!\n");
            printf("Subset 1: ");
            for(j = 0; j < len; j++) {
                if(i & (1 << j))
                    printf("%d ", arr[j]);
            }

            printf("\nSubset 2: ");
            for(j = 0; j < len; j++) {
                if(!(i & (1 << j)))
                    printf("%d ", arr[j]);
            }
            break;
        }
    }

}

int main(){
    //Sorting main codes
    // int arr[] = {5,4,3,6,10,1};
    // displayArr(arr,6);
    // // selectionSort(arr,6);
    // bubbleSort(arr,6);
    // printf("\n");
    // displayArr(arr,6);

    //String matching main code
    // char text[] = "Hello my name is Sara!";
    // char pattern[] = "name1";
    // bruteStringMatching(text,pattern,22,5)?printf("Mathced"):printf("unmatched");
    
    //Partition problem
    int arr[] = {10,20,30};
    partition(arr,3);
    
    return 0;
}