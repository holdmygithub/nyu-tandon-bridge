//program written by ak9650, Ashwin K Raghu

#include<iostream>
using namespace std;

const int ZERO=0,ONE=1,TWO=2;

int sumOfSquares(int arr[], int arrSize){
    int return_val;
    if(arrSize==ONE){
        return_val = arr[arrSize-ONE]*arr[arrSize-ONE];
    }
    else{
        return_val = sumOfSquares(arr,arrSize-ONE) + (arr[arrSize-ONE]*arr[arrSize-ONE]);
    }
    return return_val;
}

bool isSorted(int arr[], int arrSize){
    bool return_val;
    if(arrSize==ONE){
        return_val = true;
    }
    else{
        return_val = (isSorted(arr,arrSize-ONE) && (arr[arrSize-ONE] >= arr[arrSize-TWO]));
    }
    return return_val;
}

int main(){
    //part a
    cout<<"Part a"<<endl;
    int arr[] = {2, -1, 3, 10},arrSize= 4;
    cout<<"Sum of squares: "<<sumOfSquares(arr,arrSize)<<endl<<endl;

    //part b
    cout<<"Part b"<<endl;
    bool sorted;
    sorted = isSorted(arr,arrSize);
    if(sorted){
        cout<<"The array is sorted";
    }
    else{
        cout<<"The array is not sorted";
    }

}
