//submitted by ak9650,Ashwin K Raghu
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3; 

    double real_num;
    int option;
    cout<<"Please enter a Real number: "<<endl;
    cin>>real_num;
    cout<<"Choose your rounding method:"<<endl<<"1. Floor round"<<endl<<"2. Ceiling round"<<endl<<"3. Round to the nearest whole number"<<endl;
    cin>>option;
    int floor_real_num = (int) real_num;
    switch(option){
        case 1:
            cout<<floor_real_num;
            break;
        case 2:
            cout<<floor_real_num+1;
            break;
        case 3:
            if(real_num > (floor_real_num+0.5)){
                cout<<floor_real_num+1;
            }
            else{
                cout<<floor_real_num;
            }
            break;
        default:
            cout<<"Please choose from the options given";
    }
    return 0;
}