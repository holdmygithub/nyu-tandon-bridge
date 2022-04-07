// Program written by ak9650, Ashwin K Raghu

#include<iostream>
using namespace std;

int main(){
    int n,i;
    const int M=1000,D=500,C=100,L=50,X=10,V=5,I=1,ZERO=0;

    cout<<"Enter decimal number: "<<endl;
    cin>>n;
    if(n<=ZERO){
        cout<<"Input is not a positive integer";
        return 1;
    }
    cout<<n<<" is ";

    for(i=0;i<n/M;i++){
        cout<<"M";
    }

    n = n%M;

    for(i=0;i<n/D;i++){
        cout<<"D";
    }

    n = n%D;

    for(i=0;i<n/C;i++){
        cout<<"C";
    }

    n = n%C;


    for(i=0;i<n/L;i++){
        cout<<"L";
    }

    n = n%L;

    for(i=0;i<n/X;i++){
        cout<<"X";
    }

    n = n%X;

    for(i=0;i<n/V;i++){
        cout<<"V";
    }

    n = n%V;
    for(i=0;i<n;i++){
        cout<<"I";
    }

    return 0;
}