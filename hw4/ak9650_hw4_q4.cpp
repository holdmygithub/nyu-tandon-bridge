// Program written by ak9650, Ashwin K Raghu
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n,num,prod=1;
    const int NEGATIVE_ONE = -1,ZERO=0;
    cout<<"Section a"<<endl;
    cout<<"Please enter the length of the sequence: ";
    cin>>n;
    cout<<"Please enter your sequence:"<<endl;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num<=ZERO){
            cout<<"Please enter a postive integer sequence. Terminating..";
            return 1;
        }
        else{
            prod*=num;
        }
    }
    cout<<"The geometric mean is: "<<pow(prod,(double)1/n)<<endl;
    cout<<endl<<"Section b"<<endl;

    cout<<"Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:"<<endl;
    num=1,prod=1,n=0;
    while(num!=NEGATIVE_ONE){
        cin>>num;
        if(num<NEGATIVE_ONE || num==ZERO){
            cout<<"Please enter a postive integer sequence";
            return 1;
        }
        else if(num>0){
            prod*=num;
            n++;
        }
    }
    cout<<"The geometric mean is: "<<pow(prod,(double)1/n)<<endl;

    return 0;
}