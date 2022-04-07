// Program written by ak9650, ashwin k raghu
#include<iostream>
#include<string>
using namespace std;

void swap(int arr[],int i,int j){
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
}

void reverseArray(int arr[], int arrSize){
    int i,j;
    for(i=0,j=arrSize-1;i<j;i++,j--){
        swap(arr,i,j);
    }
}

void removeOdd(int arr[], int& arrSize){
    int track_index = 0;
    const int TWO=2, ZERO=0;
    for(int i=0;i<arrSize;i++){
        if(arr[i] % TWO==ZERO){
            arr[track_index] = arr[i];
            track_index++;
        }
    }
    arrSize = track_index;
}

void splitParity(int arr[], int arrSize){
    int track_index = 0;
    const int TWO=2, ZERO=0;
    for(int i=0;i<arrSize;i++){
        if(arr[i] % TWO!=ZERO){
            swap(arr,i,track_index);
            track_index++;
        }
    }
}

void printArray(int arr[], int arrSize);
int main() {
 int arr1[10] = {-49,-44,8,17,2};
 int arr1Size = 5;

 int arr2[10] = {-49,-44,8,17,2};
 int arr2Size = 5;

 int arr3[10] = {-49,-44,8,17,2};
 int arr3Size = 5;

 reverseArray(arr1, arr1Size);
 printArray(arr1, arr1Size);

 removeOdd(arr2, arr2Size);
 printArray(arr2, arr2Size);

 splitParity(arr3, arr3Size);
 printArray(arr3, arr3Size);

 return 0;
}
void printArray(int arr[], int arrSize){
 int i;

 for (i = 0; i < arrSize; i++) {
 cout<<arr[i]<<' ';
 }
 cout<<endl;
}