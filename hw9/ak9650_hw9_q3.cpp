//Program written by ak9650, Ashwin K Raghu

#include<iostream>
using namespace std;

const int ZERO = 0;
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    outPosArrSize = ZERO;
    int *positive_arr = new int[arrSize];
    for(int i=0;i<arrSize;i++){
        if(arr[i]>0){
            positive_arr[outPosArrSize] = arr[i];
            outPosArrSize++;
        }
    }
return positive_arr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    *outPosArrSizePtr = ZERO;
    int *positive_arr = new int[arrSize];
    for(int i=0;i<arrSize;i++){
        if(arr[i]>0){
            positive_arr[*outPosArrSizePtr] = arr[i];
            (*outPosArrSizePtr)++;
        }
    }
return positive_arr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){

    outPosArrSize = ZERO;
    outPosArr = new int[arrSize];
    for(int i=0;i<arrSize;i++){
        if(arr[i]>0){
            outPosArr[outPosArrSize] = arr[i];
            outPosArrSize++;
        }
    }

}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    *outPosArrSizePtr = ZERO;
    *outPosArrPtr = new int[arrSize];
    
    for(int i=0;i<arrSize;i++){
        if(arr[i]>0){
            *(*(outPosArrPtr) + *outPosArrSizePtr) = arr[i];
            *outPosArrSizePtr = *outPosArrSizePtr + 1;
        }
    }

}

void printResults(int arr[], int size){

    cout<<"\tPrinting the new array containing only positive integers: ";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl<<"\tPrinting the size of the new array containing only positive integers: ";
    cout<<size;

}

int main(){


//TEST part a)
    cout<<"Testing Part a:"<<endl;
    const int arrSize_a = 6;
    int arr_a[arrSize_a] = {3,-1,-3,0,6,4};
    int outPosArrSize_a;
    int* positive_arr_a = nullptr;
    positive_arr_a = getPosNums1(arr_a,arrSize_a,outPosArrSize_a);
    printResults(positive_arr_a,outPosArrSize_a);
    delete[] positive_arr_a;
    

//TEST part b)

    cout<<endl<<"Testing Part b:"<<endl;
    const int arrSize_b = 6;
    int arr_b[arrSize_b] = {3,-1,-3,0,6,4};
    int* outPosArrSize_b = new int;
    int* positive_arr_b = nullptr;
    positive_arr_b = getPosNums2(arr_b,arrSize_b,outPosArrSize_b);
    printResults(positive_arr_b,*outPosArrSize_b);
    delete[] positive_arr_b;

//TEST part c)

    cout<<endl<<"Testing Part c:"<<endl;
    const int arrSize_c = 6;
    int arr_c[arrSize_c] = {3,-1,-3,0,6,4};
    int outPosArrSize_c;
    int* outPosArr_c = nullptr;
    getPosNums3(arr_c,arrSize_c,outPosArr_c,outPosArrSize_c);
    printResults(outPosArr_c,outPosArrSize_c);
    delete[] outPosArr_c;


//TEST part d)

    cout<<endl<<"Testing Part d:"<<endl;
    const int arrSize_d = 6;
    int arr_d[arrSize_d] = {3,-1,-3,0,6,4};
    int* outPosArrSizePtr_d = new int;
    int* pointerOutPosArrPtr_d = nullptr;
    getPosNums4(arr_d,arrSize_d,&pointerOutPosArrPtr_d,outPosArrSizePtr_d);
    printResults(pointerOutPosArrPtr_d,*outPosArrSizePtr_d);
    delete[] pointerOutPosArrPtr_d;

    return 0;
}