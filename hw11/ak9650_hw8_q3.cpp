//program written by ak9650, Ashwin K Raghu

#include<iostream>
using namespace std;

const int ONE=1;

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

int minInArray1(int arr[], int arrSize){
    int return_val;
    if(arrSize==ONE){
        return_val = arr[arrSize-ONE];
    }
    else{
        return_val = minimum(minInArray1(arr,arrSize-ONE),arr[arrSize-ONE]);
    }
    return return_val;
}
int minInArray2(int arr[], int low, int high){
    int return_val;
    if(high==low){
        return_val = arr[high];
    }
    else{
        return_val = minimum(minInArray2(arr,low,high-ONE),arr[high]);
    }
    return return_val;
}

int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout<<res1<<" "<<res2<<endl; //should both be -9
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2])
    cout<<res3<<" "<<res4<<endl; //should both be 3
    return 0;
}