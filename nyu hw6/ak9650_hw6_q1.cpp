// Submitted by ak9650, Ashwin K Raghu
#include<iostream>
using namespace std;

int fib(int n){
    const int f1 = 1, f2 = 1,THREE=3;
    int prev=f2, prev_prev=f1,curr,i;
    if(n==1 || n==2){
        return prev;
    }

    else{
        for(i=THREE;i<=n;i++){
        curr = prev + prev_prev;
        prev_prev = prev;
        prev= curr;
    }}
    return curr;
}
int main(){
    int num;
    cout<<"Enter a positive integer: ";
    cin>>num;
    cout<<fib(num);
    return 0;
}