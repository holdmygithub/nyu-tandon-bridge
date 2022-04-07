// Submitted by ak9650, Ashwin K Raghu
#include<iostream>

using namespace std;

void printShiftedTriangle(int n, int m, char symbol){
    int i;
    for(int j=1;j<=n;j++){
        for(i=1;i<=m;i++){
            cout<<" ";
        }
        for(i=0;i<=(n-j-1);i++){
            cout<<" ";
        }

        for(i=0;i<(2*j-1);i++){
            cout<<symbol;
        }

        cout<<endl;
    }  
}
void printPineTree(int n, char symbol){
    const int ONE = 1;
    for(int i=ONE;i<=n;i++){
        printShiftedTriangle(i+1,n-i,symbol);
    }

}
int main(){
    int triangles;
    char filling_char;
    cout<<"Enter the number of triangles required in the tree: ";
    cin>>triangles;
    cout<<"Enter the character filling the tree: ";
    cin>>filling_char;
    printPineTree(triangles,filling_char);
    return 0;
}

