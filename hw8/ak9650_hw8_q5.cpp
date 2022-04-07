// Program written by ak9650, ashwin k raghu
#include<iostream>
#include<string>
#include<ctime>
using namespace std;


int main(){
    string Last_Name, First_Name, Middle_Initial;
    cout<<"Please enter the full name (first name, then middle name or initial, and then last name):"<<endl;
    cin>>First_Name>>Middle_Initial>>Last_Name;
    cout<<Last_Name<<", "<<First_Name<<" "<<Middle_Initial[0]<<".";
    return 0;
}