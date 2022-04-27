#include<iostream>
#include<fstream>
#include<string>

using namespace std;


class Employee{
    private:
        int id_number,hours_worked;
        double hourly_pay_rate;
        string name;

    public:

    Employee(int id_num, double hpr, string name_employee) : id_number(id_num), hourly_pay_rate(hpr), name(name_employee), hours_worked(0){}

    int getId() const{
        return id_number;
    }

    int getHoursWorked() const{
        return hours_worked;
    }

    double getHourlyPayRate() const{
        return hourly_pay_rate;
    }

    string getName() const{
        return name;
    }
    void addEmployeeHours(int hrs){
        hours_worked+=hrs;
    }





};
