// Program written by ak9650, Ashwin K Raghu
#include<iostream>
using namespace std;

int main(){
    int n;
    const int ZERO=0;
    cout<<"Please enter a positive integer n: ";
    cin>>n;
    if(n<=ZERO){
        cout<<"Input is not a postive integer";
        return 1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int k=2*n-1-(2*i);k>0;k--){
            cout<<"*";
        }
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<endl;
    }

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int k=2*n-1-(2*i);k>0;k--){
            cout<<"*";
        }
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}