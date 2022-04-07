// submitted by  ak9650, ashwin k raghu


#include<iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay){
    int i;
    const int NUM_DAYS_PER_WEEK = 7, ONE=1;
    cout<<"Mon\tTue\tWed\tThr\tFri\tSat\tSun"<<endl;

    for(i = 1; i<startingDay; i++){
        cout<<"\t";
    }

    int day = startingDay-1;
    for(i=1; i<=numOfDays; i++){
        day = day%NUM_DAYS_PER_WEEK + ONE;
        cout<<i<<"\t";
        if(day==NUM_DAYS_PER_WEEK){
            cout<<endl;
        }
    }
    return day;
}

bool isLeapYear(int year){
    const int FOUR=4,HUNDRED=100,FOURHUNDRED=400;
    bool leap_year;
    if(((year%FOUR==0) && (year%HUNDRED!=0)) || (year%FOURHUNDRED==0)){
        leap_year = true;
    }
    else{
        leap_year = false;
    }
    return leap_year;
}
void printYearCalender(int year, int startingDay){
    int numOfDays = 0, month_start_day = startingDay;
    const int MONTHS_IN_A_YEAR = 12,NUM_DAYS_PER_WEEK = 7,MONDAY=1;
    const int JAN=1,FEB=2,MAR=3,APR=4,MAY=5,JUN=6,JUL=7,AUG=8,SEPT=9,OCT=10,NOV=11,DEC=12;
    string month;

    for(int i = 1; i <= MONTHS_IN_A_YEAR; i++){
        if(i == JAN){
            month = "January";
            numOfDays = 31;

        }else if(i == FEB){
            month = "February";
            if(isLeapYear(year)){
                numOfDays = 29;
            }
            else{
                numOfDays = 28;
            }
        }else if(i == MAR) {
            month = "March";
            numOfDays = 31;
        }else if(i == APR){
            month = "April";
            numOfDays = 30;
        }else if(i == MAY){
            month = "May";
            numOfDays = 31;
        }else if(i == JUN){
            month = "June";
            numOfDays = 30;
        }else if(i == JUL){
            month = "July";
            numOfDays = 31;
        }else if(i == AUG){
            month = "August";
            numOfDays = 31;
        }else if(i == SEPT){
            month = "September";
            numOfDays = 30;
        }else if(i == OCT){
            month = "October";
            numOfDays = 31;
        }else if(i == NOV){
            month = "November";
            numOfDays = 30;
        }else if(i == DEC){
            month = "December";
            numOfDays = 31;
        }

        cout<<month<<" "<<year<<endl;
        month_start_day = (printMonthCalender(numOfDays,month_start_day)%NUM_DAYS_PER_WEEK) + 1;
        if(month_start_day==MONDAY){
            cout<<endl;
        }
        else{
            cout<<endl<<endl;
        }
    }
}
int main(){
    int startingDay,year;
    cout<<"Please enter a year: ";
    cin>>year;
    cout<<"Please enter the starting day (a number 1-7 that represents the day in the week of 1/1 in that year (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.): ";
    cin>>startingDay;
    cout<<endl;
    printYearCalender(year,startingDay);
    return 0;
}