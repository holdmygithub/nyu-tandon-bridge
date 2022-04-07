// Program written by ak9650, Ashwin K Raghu
#include<iostream>
#include<cmath>
using namespace std;

int main(){

    int num,i=0;
    const int ZERO = 0;
    cout<<"Enter decimal number: "<<endl;
    cin>>num;
    if(num<=ZERO){
        cout<<"Input is not a positive integer";
        return 1;
    }
    cout<<"The binary representation of "<<num<<" is ";
    while(pow(2,i)<=num){
        i++;
    }

    for(int j=i-1;j>=0;j--){
        if(num>=pow(2,j)){
            cout<<1;
            num = num% (int)pow(2,j);
        }
        else{
            cout<<0;
        }
    }
    cout<<endl;

    return 0;
}