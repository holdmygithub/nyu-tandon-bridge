//submitted by ak9650,Ashwin K Raghu
#include<iostream>
#include<string>
using namespace std;

int main(){
    char temp;
    string day;
    int t1,t2,duration_min;
    double cost,start_time_hours;  

    cout<<"Enter call start time in 24 hour format: ";
    cin>>t1>>temp>>t2;
    start_time_hours = t1 + (t2/60.0);
    cout<<"Enter day of the week (choose from Mo Tu We Th Fr Sa Su): ";
    cin>>day;
    cout<<"Enter duration of call in minutes: ";
    cin>>duration_min;

    if(day=="Sa" or day=="Su"){
        cost = duration_min*0.15;
    }
    else if((day=="Mo") || (day == "Tu") || (day == "We") || (day == "Th") || (day == "Fr")){
        if(start_time_hours < 8 || start_time_hours > 18){
            cost = duration_min*0.25;
        }
        else{
            cost = duration_min*0.4;
        }
    }
    else{
        cout<<"Enter day of the week in the required format";
        return 1;
    }
    cout<<"Cost of the call is $"<<cost;
    return 0;
}