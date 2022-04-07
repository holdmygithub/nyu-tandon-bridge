//submitted by ak9650,Ashwin K Raghu
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    double a,b,c;
    cout<<"Please enter value of a: ";
    cin>>a;
    cout<<"Please enter value of b: ";
    cin>>b;
    cout<<"Please enter value of c: ";
    cin>>c;

    if(a!=0){
        double discriminant;
        discriminant = (b*b) - (4*a*c);
        if(discriminant > 0){
            double solution1,solution2;
            solution1 = (-b + sqrt(discriminant))/(2*a);
            solution2 = (-b - sqrt(discriminant))/(2*a);
            cout<<"This equation has two real solutions x1 = "<<solution1<<" and "<<"x2 = "<<solution2;
        }
        else if(discriminant < 0){
            cout<<"This equation has no real solution";
        }
        else{
            double solution1;
            solution1 = -b /(2*a);
            cout<<"This equation has a single real solution x = "<<solution1;
        }
        }
    else if(b!=0){
        double solution1;
        solution1 = -c/b;
        cout<<"This equation has a single real solution x = "<<solution1;
    }
    else if(c!=0){
        cout<<"This equation has no solution";
    }
    else{
        cout<<"This equation has infinite number of solutions";
    }
    return 0;
}