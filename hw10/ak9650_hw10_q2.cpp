//Program written by ak9650, Ashwin K Raghu

#include<iostream>
#include<string>
using namespace std;

const char whitespace = ' ';
const int ONE = 1;

int* findMissing(int arr[], int n, int& resArrSize){
    resArrSize = n+ONE;
    bool numbers_present[n+ONE] = {false};
    int num;

    for(int i=0;i<n;i++){
        num = arr[i];
        if(numbers_present[num]==false){
            resArrSize--;
            numbers_present[num] = true;
        }
    }

    int* resArr = new int[resArrSize], count=0;
    for(int i=0;i<(n + ONE);i++){
        if(numbers_present[i]==false){
            resArr[count++] = i;
        }
    }
    return  resArr;
}

void printElements(int *resArr, int resArrSize){
    for(int i=0;i<resArrSize;i++){
        cout<<resArr[i]<<endl;
    }
}

int main(){
    int arr[] = {3, 1, 3, 0, 6, 4}, n = 6, resArrSize = 0, *resArr;
    resArr = findMissing(arr,n,resArrSize);
    cout<<"Logical size of array containing missing numbers: "<<resArrSize<<endl;
    cout<<"Printing the array containing missing numbers:"<<endl;
    printElements(resArr, resArrSize);
    delete[] resArr;
    resArr = nullptr;
    return 0;
}
