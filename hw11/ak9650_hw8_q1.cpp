//program written by ak9650, Ashwin K Raghu

#include<iostream>
using namespace std;
const int ONE = 1,ZERO = 0;
const char star = '*',dash = '-';

void printRecurShape(int n,char shape){
    if(n==ZERO){
        return;
    }
    else{
        printRecurShape(n-ONE,shape);
        cout<<shape;
    }
}
void printTriangle(int n){
    if(n==ZERO){
        return;
    }
    else{
        printTriangle(n-ONE);
        printRecurShape(n,star);
        cout<<"\n";

    }
}

void printOppositeTriangles(int n){
    if(n==ZERO){
        return;
    }
    else{
        printRecurShape(n,star);
        cout<<"\n";
        printOppositeTriangles(n-ONE);
        printRecurShape(n,star);
        cout << "\n";
    }
}

void printRuler(int n){
    if(n==ZERO){
        return;
    }

    printRuler(n-1);
    printRecurShape(n,dash);
    cout<<"\n";
    printRuler(n-1);
}

int main(){
    int n=4;
    // part a)
    cout<<"printTriangle output"<<endl;
    printTriangle(n);
    // part b)
    cout<<"printOppositeTriangles output"<<endl;
    printOppositeTriangles(n);
    // part c)
    cout<<"printRuler"<<endl;
    printRuler(n);
}