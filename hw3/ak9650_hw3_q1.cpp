//submitted by ak9650,Ashwin K Raghu

#include<iostream>
using namespace std;

int main(){
    double tax_rate,first_price,total_price,second_price,baseprice;
    char club_card;
    cout<<"Enter price of first item: ";
    cin>>first_price;
    cout<<"Enter price of second item: ";
    cin>>second_price;
    baseprice = first_price + second_price;
    
    if(first_price<second_price){
        total_price = first_price/2 + second_price;
    }
    else{
        total_price = second_price/2 + first_price;
    }
    cout<<"Does customer have a club card? (Y/N): ";
    cin>>club_card;
    if(club_card=='y' || club_card=='Y'){
        total_price = total_price*0.9;
    } else if(club_card !='n' && club_card != 'N'){
        cout<<"Enter 'y' or 'y' for 'yes'; 'N' or 'n' for 'no'";
        return 1;
    }
    cout<<"Enter tax rate, e.g. 5.5 for 5.5\% tax: ";
    cin>>tax_rate;
    cout<<"Base price: "<<baseprice<<endl;
    cout<<"Price after discounts: "<<total_price<<endl;
    total_price = total_price + total_price*tax_rate/100;
    cout<<"Total price: "<<total_price<<endl;
    return 0;
}