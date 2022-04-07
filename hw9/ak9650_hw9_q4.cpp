//Program written by ak9650, Ashwin K Raghu

#include<iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize){
    int* newArr = new int[arrSize];
    int odd =0, even=arrSize-1;
    
    for(int i=0;i<arrSize;i++){
        if(arr[i]%2==0){
            newArr[even--] = arr[i];
        }
        else{
            newArr[odd++] = arr[i];
        }
    }
    
    for(int i=0;i<arrSize;i++){
        arr[i] = newArr[i];
    }
    delete[] newArr;
}

int main(){
    const int arrSize = 6;
    int arr[arrSize] = {5,2,11,7,6,4};
    oddsKeepEvensFlip(arr,arrSize);
    cout<<"Results after reordering the array using oddsKeepEvensFlip function: "<<endl;
    for(int i=0;i<arrSize;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}