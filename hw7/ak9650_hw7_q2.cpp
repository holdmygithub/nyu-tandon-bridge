// submitted by  ak9650, ashwin k raghu

#include<iostream>
#include<cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs){
    const int ONE = 1,TWO=2;
    outSumDivs = ONE; //1 divides every integer
    outCountDivs = ONE; //1 divides every integer
    for(int i=TWO;i<=sqrt(num);i++){
        if(i==sqrt(num)){
            outSumDivs += i;
            outCountDivs += ONE;
        }
        else if(num%i==0){
            outSumDivs += i + (num/i);
            outCountDivs += TWO; //i and (num/i) divides num
        }
    }
}

bool isPerfect(int num){
    int outCountDivs, outSumDivs, perfect;
    analyzeDividors(num,outCountDivs,outSumDivs);
    if(outSumDivs==num){
        perfect = true;
    }
    else{
        perfect = false;
    }
    return perfect;
}

int main(){
    int M;
    cout<<"Enter a positive integer (>=2): ";
    cin>>M;

    cout<<"All the perfect numbers between 2 and "<<M<<":"<<endl;
    for(int i = 2; i <= M; i++){
        if(isPerfect(i)){
            cout<<i<<"  ";
        }
    }
    cout<<endl;

    cout<<"All pairs of amicable numbers that are between 2 and "<<M<<":"<<endl;
    int outCountDivs,outSumDivs,outCountDivs2,outSumDivs2,flag=0;
    for(int i = 2; i <= M; i++){
        analyzeDividors(i, outCountDivs, outSumDivs);
        analyzeDividors(outSumDivs, outCountDivs2, outSumDivs2);

        if((i==outSumDivs2)&&(i>outSumDivs)){
            cout<<"("<<outSumDivs<<","<<i<<")"<<endl;
            flag=1;
        }
    }
    if(flag==0){
        cout<<"None";
    }
    return 0;
}