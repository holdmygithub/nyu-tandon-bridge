//program written by ak9650, Ashwin K Raghu

#include<iostream>
using namespace std;

const int THREE=3,ONE=1,TWO=2;

int minimum(int a,int b){
    int min;
    if(a>=b){
        min = b;
    }
    else{
        min = a;
    }
    return min;
}

int jumpIt(int arr[],int arrSize){
    int return_val;
    if(arrSize<=THREE){
        return_val = arr[arrSize-ONE];
    }
    else{
        return_val = minimum(jumpIt(arr,arrSize-ONE),jumpIt(arr,arrSize-TWO)) + arr[arrSize-ONE];
    }

    return return_val;

}

int main(){
    int arr[] = {0,3,80,6,57,10},arrSize = 6;
    cout<<"Lowest cost: "<<jumpIt(arr,arrSize);
    return 0;
}