//submitted by ak9650,Ashwin K Raghu
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    double bmi,height,weight;
    string status;
    cout<<"Please enter weight (in pounds): ";
    cin>>weight;
    weight = weight*0.453592; //convert pound to kg
    cout<<"Please enter height (in inches): ";
    cin>>height;
    height = height*0.0254; //convert inches to m

    bmi = weight/(height*height);
    if(bmi<18.5){
        status= "Underweight";
    }
    else if(bmi <25){
        status= "Normal";
    }
    else if(bmi < 30){
        status= "Overweight";
    }
    else{
        status= "Obese";
    }
    
    cout<<"The weight status is: "<<status;
    return 0;
}