// Submitted by ak9650, Ashwin K Raghu
#include<iostream>
using namespace std;

double eApprox(int n){
    const int first_term = 1;
    double sum = first_term, factorial_term = first_term;
    for(int i=1;i<=n;i++){
        factorial_term = factorial_term/i;
        sum = sum + factorial_term;
    }
    return sum;
}

int main() {
    cout.precision(30);
    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    return 0;
}