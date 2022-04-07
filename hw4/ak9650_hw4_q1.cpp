// Program written by ak9650, Ashwin K Raghu

#include<iostream>
using namespace std;

int main(){
    int n,count=0,even_num=2;
    const int ZERO=0;
    cout<<"Please enter a positive integer: ";
    cin>>n;
    if(n<=ZERO){
        cout<<"Input is not positive a integer";
        return 1;
    }
    cout<<"section a"<<endl;
    while(count<n){

        cout<<even_num<<endl;
        even_num+=2;
        count++;

    }
    cout<<"section b"<<endl;
    cout<<"Please enter a positive integer: ";
    cin>>n;

    if(n<=ZERO){
        cout<<"Input is not positive a integer";
        return 1;
    }
    even_num = 2;
    for(count=0;count<n;count++){
        cout<<even_num<<endl;
        even_num+=2;
    }
    return 0;
}