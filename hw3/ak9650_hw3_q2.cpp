//submitted by ak9650,Ashwin K Raghu
#include<iostream>
#include<string>
using namespace std;

int main(){
    string name,status;
    int year_graduation, year_curr;
    int option;
    cout<<"Please enter your name: ";
    cin>>name;
    cout<<"Please enter your graduation year: ";
    cin>>year_graduation;
    cout<<"Please enter current year: ";
    cin>>year_curr;
    
    option = year_graduation-year_curr;
    switch(option){
        case 1:
            status = "Senior";
            break;
        case 2:
            status = "Junior";
            break;
        case 3:
            status = "Sophomore";
            break;
        case 4:
            status = "Freshman";
            break;
        default:
            if(option > 4){
                status = "Not in college yet";
            }
            else{
                status = "Graduated";
            }
    }
    cout<<name<<", you are a "<<status;
    return 0;
}