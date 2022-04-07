// Program written by ak9650, ashwin k raghu
#include<iostream>
using namespace std;

int minInArray(int arr[], int arrSize){
    int min = arr[0];
    for(int i=1;i<arrSize;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

void printIndices(int arr[], int min, const int SIZE){
    for(int i = 0;i<SIZE;i++){
        if(arr[i]==min){
            cout<<i<<" ";
        }
    }
}

int main(){
    const int SIZE=20;
    int arr[SIZE],min,i;
    cout<<"Please enter "<<SIZE<<" integers separated by a space:"<<endl;
    for(i=0;i<SIZE;i++){
        cin>>arr[i];
    }
    min = minInArray(arr,SIZE);
    cout<<"The minimum value is "<<min<<", and it is located in the following indices: ";
    printIndices(arr,min,SIZE);
    return 0;
}