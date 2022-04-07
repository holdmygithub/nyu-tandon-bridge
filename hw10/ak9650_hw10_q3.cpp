//Program written by ak9650, Ashwin K Raghu

#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int END = -1;

int* increaseMaxSize(int* arr, int& max_size, const int extension_size){
    int *temp = new int[max_size + extension_size];
    for(int i=0;i<max_size;i++){
        temp[i] = arr[i];
    }
    max_size = max_size + extension_size;
    return temp;
}

void printLines(int search_indices[],int count, int search_num){

    cout<<search_num<<" shows in lines ";
    for(int i=0;i<count-1;i++){
        cout<<search_indices[i]<<", ";
    }
    cout<<search_indices[count-1]<<".";
}

void main1(){
    const int extension_size = 10;
    int max_size = 5, size=0, num=0, search_num;
    int *arr = new int[max_size];
    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl<<"End your input by typing -1."<<endl;
    while(num!=END){
        if(size<max_size){
            cin>>num;
            if(num!=END)
                arr[size++] = num;
        }
        if(size==max_size){
            arr = increaseMaxSize(arr,max_size,extension_size);
        }
    }

    cout<<"Please enter a number you want to search."<<endl;
    cin>>search_num;

    int search_indices[size];
    int count = 0;
    for(int i=0;i<size;i++){
        if(arr[i]==search_num){
            search_indices[count++] = i+1;
        }
    }

    if(count==0){
        cout<<search_num<<" not found in the sequence.";
    }
    else{

        printLines(search_indices,count,search_num);
    }
    delete[] arr;
    arr = nullptr;
}

void main2(){
    int num=0, search_num;
    int count = 0;
    vector<int> arr;
    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl<<"End your input by typing -1."<<endl;
    while(num!=END){
        cin>>num;
        if(num!=END)
            arr.push_back(num);
    }

    cout<<"Please enter a number you want to search."<<endl;
    cin>>search_num;

    int size = arr.size();
    int search_indices[size];

    for(int i=0;i<size;i++){
        if(arr[i]==search_num){
            search_indices[count++] = i+1;
        }
    }

    if(count==0){
        cout<<search_num<<" not found in the sequence.";
    }
    else{
        printLines(search_indices,count,search_num);
    }
}

int main(){
   cout<<"VERSION 1"<<endl<<endl;
   main1();
   cout<<endl<<endl;
   cout<<"VERSION 2"<<endl<<endl;
   main2();
}