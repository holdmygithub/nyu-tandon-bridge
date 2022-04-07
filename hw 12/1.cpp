//This program is written by ak9650, Ashwin K Raghu
#include<iostream>
using namespace std;
const char DASH = '-';
const int A_DOLLAR_IN_CENTS = 100,ZERO=0;

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
            if((dollars * cents)>0){
                all_cents = dollars*A_DOLLAR_IN_CENTS + cents;
            }
            else{
                cout<<"Erroneous input. Please keep both dollars and cents positive or negative";
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

istream& operator>>(istream& ins, Money& amount){
    char first, decimal;
    bool negative;
    long dollars;
    int cents;

    ins >> first;
    if(first==DASH){
        negative = true;
        ins >> first;
    }

    ins >> dollars;
    ins >> cents;

    if(cents<A_DOLLAR_IN_CENTS){
        amount.all_cents = dollars*100 + cents;
        if(negative){
            amount = -amount;
        }
    }
    else{
        cout<<"Cents (after decimal point) must be less than "<<A_DOLLAR_IN_CENTS;
    }
}

ostream& operator<<(ostream& outs, const Money& amount){
    long dollars;
    int cents;
    int abs_value = amount.all_cents;

    if(amount<ZERO){
        abs_value = -abs_value;
    }

}

class Cheque{
    private:
        int check_number;
        Money check_amount;
        bool check_cashed;
    public:
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

        friend istream& operator>>(istream& ins, Cheque& cheque);
        friend ostream& operator<<(ostream& outs, Cheque& cheque);

        bool operator<(const Cheque& chk){
            return check_number<chk.check_number;
        }
}