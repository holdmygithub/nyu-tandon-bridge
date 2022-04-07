// Program written by ak9650, Ashwin K Raghu
#include<iostream>
using namespace std;

int main(){
    int n,digit,num,odd,even;
    const int ZERO=0,TEN=10;
    cout<<"Please enter a positive integer n: ";
    cin>>n;
    if(n<=ZERO){
        cout<<"Input is not a positive integer";
    }

    for(int i=1;i<=n;i++){
        odd = 0;
        even = 0;
        num = i;

        while(num>0){
            digit = num%TEN;
            num = num/TEN;
            if(digit%2==0){
                even++;
            }
            else{
                odd++;
            }

        }
        if(even>odd){
            cout<<i<<endl;
        }

    }
    return 0;
}