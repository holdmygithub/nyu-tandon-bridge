// Program written by ak9650, ashwin k raghu
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

const string ORIGINAL_PIN = "12345";
const int MAX_SECRET_NUM = 3, DIGITS_COUNT = 10, ONE=1;

void generateRandomMapping(int map[]){
    srand(time(0));
    for(int i=0;i<DIGITS_COUNT;i++){
        map[i] = (rand()%MAX_SECRET_NUM + ONE);
    }
}

void printMapping(int map[]){
    cout<<"PIN:\t";
    for(int i=0;i<DIGITS_COUNT;i++){
       cout<<i<<" ";
    }
    cout<<endl<<"NUM:\t";
    for(int i=0;i<DIGITS_COUNT;i++){
       cout<<map[i]<<" ";
    }
    cout<<endl;
}

void validatePin(int pin_length,int map[],string input_pin){
    const char CHAR_ZERO = '0';
    int flag=0;
    bool valid;
    for(int i=0;i<pin_length;i++){
        if(map[ORIGINAL_PIN[i] - CHAR_ZERO]!=(input_pin[i] - CHAR_ZERO)){
            flag++;
        }
    }
    if(flag==0){
        cout<<"Your PIN is correct";
    }
    else{
        cout<<"Your PIN is not correct";
    }
}

int main(){
    int map[DIGITS_COUNT], pin_length = ORIGINAL_PIN.length(),flag=0;
    string input_pin;
    generateRandomMapping(map);
    cout<<"Please enter your PIN according to the following mapping:"<<endl;
    printMapping(map);
    cin>>input_pin;
    if(input_pin.length()==pin_length){
        validatePin(pin_length,map,input_pin);
    }
    else{
        cout<<"Length mismatch: Wrong pin";
    }
    return 0;
}