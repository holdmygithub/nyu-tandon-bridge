//Program written by Ashwin K Raghu, ak9650

#include<iostream>
#include<vector>

using namespace std;

const int MIN_VALUE = 0, MAX_VALUE = 1, ZERO = 0, ONE=1, SIZE_OF_MINMAX_VECTOR=2;

vector<int> findMinMax(const vector<int>& arr, int left, int right){
    vector<int> results(SIZE_OF_MINMAX_VECTOR), left_results(SIZE_OF_MINMAX_VECTOR), right_results(SIZE_OF_MINMAX_VECTOR);
    if(right - left <=ONE){
            results[MIN_VALUE] = min(arr[left],arr[right]);
            results[MAX_VALUE] = max(arr[left],arr[right]);
    }
    else{
        int middle = (left+right)/2;
        left_results = findMinMax(arr,left,middle);
        right_results = findMinMax(arr,middle,right);

        results[MIN_VALUE] = min(left_results[MIN_VALUE],right_results[MIN_VALUE]);
        results[MAX_VALUE] = max(left_results[MAX_VALUE],right_results[MAX_VALUE]);
    }
    return results;
}

void printMinMax(const vector<int>& results){
    cout<<"The minimum value in the given array is: "<<results[MIN_VALUE]<<endl;
    cout<<"The maximum value in the given array is: "<<results[MAX_VALUE];
}

void printGivenArray(const vector<int>& arr){
    cout<<"Given array:"<<endl;
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl<<endl;
}
int main(){
    vector<int> arr = {4,2,1,8,7,6,123}, results;
    results = findMinMax(arr,ZERO,arr.size()-1);
    printGivenArray(arr);
    printMinMax(results);
}