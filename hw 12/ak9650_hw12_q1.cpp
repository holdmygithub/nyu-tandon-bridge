//This program is written by ak9650, Ashwin K Raghu
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const char DASH = '-',DOLLAR_SYMBOL='$',DECIMAL_SYMBOL='.';
const int A_DOLLAR_IN_CENTS = 100,ZERO=0,TEN=10;

class Money{

    private:
        long all_cents;

    public:

        friend Money operator+(const Money& amount1, const Money& amount2);
        //Returns the sum of the values of amount1 and amount2.
        friend Money operator-(const Money& amount1, const Money& amount2);
        //Returns amount1 minus amount2.
        friend Money operator-(const Money& amount);
        //Returns the negative of the value of amount.
        friend bool operator==(const Money& amount1, const Money& amount2);
        //Returns true if amount1 and amount2 have the same value; false otherwise.
        friend bool operator<(const Money& amount1, const Money& amount2);
        //Returns true if amount1 is less than amount2; false otherwise.
        friend bool operator<(const Money& amount1, const int &val);
        //Returns true if amount1 value is less than a given integer value; false otherwise.
        Money(long dollars, int cents){
            if((dollars * cents)>ZERO){
                all_cents = dollars*A_DOLLAR_IN_CENTS + cents;
            }
            else{
                cout<<"Erroneous input. Please keep both dollars and cents positive or negative"<<endl;
            }
        }
        //Initializes the object so its value represents an amount with
        //the dollars and cents given by the arguments. If the amount
        //is negative, then both dollars and cents should be negative.
        Money(long dollars){
            all_cents = dollars * A_DOLLAR_IN_CENTS;
        }
            
        Money():all_cents(ZERO){}
        //Initializes the object so its value represents $0.00.
        double get_value() const{
            return all_cents;
        }
        //Returns the amount of money recorded in the data portion of the calling
        //object.
        friend istream& operator>>(istream& ins, Money& amount);
        //Overloads the >> operator so it can be used to input values of type
        //Money. Notation for inputting negative amounts is as in − $100.00.
        //Precondition: If ins is a file input stream, then ins has already been
        //connected to a file.
    
        friend ostream& operator<<(ostream& outs, const Money& amount);
        //Overloads the << operator so it can be used to output values of type
        //Money. Precedes each output value of type Money with a dollar sign.
        //Precondition: If outs is a file output stream, then outs has already been
        //connected to a file.

        Money(const Money& amount){
            all_cents = amount.all_cents;
        }
};

Money operator+(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

Money operator-(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator-(const Money& amount){
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator==(const Money& amount1, const Money& amount2){
    return amount1.all_cents == amount2.all_cents;
}

bool operator<(const Money& amount1, const Money& amount2){
    return amount1.all_cents < amount2.all_cents;
}

bool operator<(const Money& amount1, const int &val){
    return amount1.all_cents < val;
}

istream& operator>>(std::istream& ins, Money& amount){
    char first, decimal;
    bool negative;
    long dollars;
    int cents;

    ins>>first;
    if(first==DASH){
        negative = true;
        ins>>first;
    }


    ins>>dollars;
    ins>>decimal;
    ins>>cents;

    if(first!=DOLLAR_SYMBOL || decimal!=DECIMAL_SYMBOL){
        cout<<"Currency error"<<endl;
        exit(1);
    }

    if(cents<A_DOLLAR_IN_CENTS){
        amount.all_cents = dollars*A_DOLLAR_IN_CENTS + cents;
        if(negative){
            amount = -amount;
        }
    }
    else{
        cout<<"Cents (after decimal point) must be less than "<<A_DOLLAR_IN_CENTS<<endl;
        exit(1); //terminate
    }
    return ins;
}

ostream& operator<<(ostream& outs, const Money& amount){
    int cents;
    long dollars,abs_value = amount.all_cents;

    if(amount<ZERO){
        abs_value = -abs_value;
        outs<<DASH;
    }

    dollars = abs_value/A_DOLLAR_IN_CENTS;
    cents = abs_value%A_DOLLAR_IN_CENTS;
    outs<<DOLLAR_SYMBOL<<dollars<<DECIMAL_SYMBOL;

    if(cents<TEN)
        outs<<ZERO;
    outs<<cents;
    return outs;
}

class check{
    private:
        int check_number;
        Money check_amount;
        bool check_cashed;
    public:
        check(): check_number(ZERO),check_cashed(false){}
        int get_check_number() const{
            return check_number;
        }
        Money get_check_amount() const{
            return check_amount;
        }
        bool get_check_cashed() const{
            return check_cashed;
        }

        void set_check_number(const int check_num){
            check_number = check_num;
        }

        void set_check_amount(const Money &amt){
            check_amount = amt;
        }

        void set_check_cashed(const bool cashed){
            check_cashed = cashed;
        }

        friend istream& operator>>(istream& ins, check& check);
        friend ostream& operator<<(ostream& outs, check& check);

        bool operator<(const check& chk){
            return check_number<chk.check_number;
        }
};


istream& operator>>(istream& ins, check& check){
    char cashed;
    ins>>check.check_number>>check.check_amount>>cashed;
    if(cashed=='y' || cashed =='Y'){
        check.check_cashed = true;
    }
    else if(cashed=='n' || cashed =='N'){
        check.check_cashed = false;
    }
    else{
        cout<<"Error in inputs of check"<<endl;
        exit(1); //terminate
    }

    return ins;

}
ostream& operator<<(ostream& outs, check& check){
    outs<<"Check number: "<<check.check_number<<", Check amount: "<<check.check_amount;
    if(check.check_cashed){
        cout<<", check cashed.";
    }
    else{
        cout<<", check not cashed.";
    }
    return outs;
}

int main(){
    vector<check> checks;
    Money new_balance, curr_balance, old_balance,total_deposit, curr_deposit, deposit_input, checks_cashed_amount;
    check check_input;
    char flag;

    cout<<endl<<"Checkbook Balancing Program."<<endl;
    cout<<"Enter your current bank balance (format: $dollars.cents or -$dollars.cents where cents < "<<A_DOLLAR_IN_CENTS<<". E.g.: $20.10)"<<endl;
    cin>>curr_balance;
    cout<<"Enter your old bank balance (format: $dollars.cents or -$dollars.cents where cents < "<<A_DOLLAR_IN_CENTS<<". E.g.: -$20.45)"<<endl;
    cin>>old_balance;
    cout<<endl;
    cout<<"Would you like to add deposit information? (press y to enter, another letter to exit)"<<endl;
    cin>>flag;
    while(flag=='y' || flag=='Y'){
        cout<<"Enter deposit amount (format: $dollars.cents where cents < "<<A_DOLLAR_IN_CENTS<<". E.g.: $20.45)"<<endl;
        cin>>curr_deposit;
        total_deposit = total_deposit + curr_deposit;

        cout<<"Would you like to add another deposit? (press y to enter, another letter to exit)"<<endl;
        cin>>flag;
    }

    cout<<endl<<"Would you like to add check information? (press y to enter, another letter to exit)"<<endl;
    cin>>flag;

    while(flag=='y' || flag=='Y'){
        cout<<"Enter check number, check amount, y/n indicating if the check is cashed or not. (egs: 12445 $10.34 y)"<<endl;
        cin>>check_input;
        checks.push_back(check_input);
        if(check_input.get_check_cashed()){
            checks_cashed_amount = checks_cashed_amount + check_input.get_check_amount();
        }
        cout<<"Would you like to add another check information? (press y to enter, another letter to exit)"<<endl;
        cin>>flag;
    }
    
    new_balance = old_balance + total_deposit - checks_cashed_amount;

    cout<<endl;
    cout<<"Total of checks cashed: "<<checks_cashed_amount<<endl;
    cout<<"Total of deposits: "<<total_deposit<<endl;
    cout<<"New balance calculated: "<<new_balance<<endl;
    cout<<"Difference of calculated new balance from current balance: "<<new_balance - curr_balance<<endl<<endl;

    sort(checks.begin(),checks.end());
    
    cout<<"Checks cashed since previous balancing:"<<endl;
    for(int i=0;i<checks.size();i++){
        if(checks[i].get_check_cashed()){
            cout<<checks[i]<<endl;
        }
    }

    cout<<endl<<"Checks not cashed:"<<endl;
    for(int i=0;i<checks.size();i++){
        if(!checks[i].get_check_cashed()){
            cout<<checks[i]<<endl;
        }
    }

    cout<<endl;
    return 0;
}