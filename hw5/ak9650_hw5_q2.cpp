//Homework submitted by ak9650, Ashwin K Raghu
//hw5 q2

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    const int MAX_GUESSES_AVAILABLE = 5,ZERO=0,ONE=1,DEFAULT_MIN = 0, DEFAULT_MAX=100;
    int random_num,l=DEFAULT_MIN,r=DEFAULT_MAX,guess,guess_num=MAX_GUESSES_AVAILABLE;
    srand(time(0));

    random_num = (rand()%DEFAULT_MAX)+ONE;
    cout<<"I thought of a number between 1 and 100! Try to guess it."<<endl;
    while(guess_num>0){
        cout<<"Range: ["<<l<<", "<<r<<"], Number of guesses left: "<<guess_num<<endl<<"Your guess: ";
        cin>>guess;
        guess_num--;

        if(guess==random_num){
            cout<<"Congrats! You guessed my number in "<<MAX_GUESSES_AVAILABLE-guess_num;
            if(guess_num==MAX_GUESSES_AVAILABLE-1){
                cout<<" guess.";
            }
            else{
                cout<<" guesses.";
            }
            return 0;
        }
        else if(guess_num==0){
            cout<<"Out of guesses! My number is "<<random_num;
            return 0;
        }

        else if(guess<random_num){
            cout<<"Wrong! My number is bigger."<<endl<<endl;
            if (guess>=l) {
                l = guess + 1;
            }
        }

        else{
            cout << "Wrong! My number is smaller."<<endl<<endl;
            if(guess<=r) {
                r = guess - 1;
            }
        }
    }
    return 0;
}