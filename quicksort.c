#include <stdio.h>
#include <stdlib.h>

int midean(int arr[],int high, int low){
    int mid = low + (high-low)/2;
    return arr[mid];
}


int partition(int arr[], int low, int high){
    int mid = low + (high-low)/2;
    int pivot = arr[mid];
    int temp = arr[mid];
    arr[mid] = arr[high];
    arr[high] = temp;
    int i = low-1;
    for (int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

void displayArr(int arr[], int len){
    for(int i=0;i<len;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {9,4,5,3,1,2,7};
    displayArr(arr,7);
    quicksort(arr,0,6);
    displayArr(arr,7);
    return 0;
}