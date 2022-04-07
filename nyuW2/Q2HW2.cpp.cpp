#include<iostream>
using namespace std;

int main(){
    int dollars,cents,quarters,dimes,nickels,pennies,reminder;
    cout<<"Please enter your amount in the format of dollars and cents separated by a space:"<<endl;
    cin>>dollars>>cents;
    reminder = dollars * 100 + cents;
    
    quarters = reminder/25;
    reminder = reminder%25;

    dimes = reminder/10;
    reminder = reminder%10;


    nickels = reminder/5;
    reminder = reminder%5;
  

    pennies = reminder;
   
    cout<<dollars<<" dollars and "<<cents<<" cents are:"<<endl;
    cout<<quarters<<" quarters,"<<dimes<<" dimes,"<<nickels<<" nickels and "<<pennies<<" pennies";
    return 0;
}