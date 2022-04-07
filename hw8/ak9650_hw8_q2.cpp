// Program written by ak9650, ashwin k raghu
#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str){
    int i,j,flag=0;
    bool palindrome = true;
    for(i=0,j=str.length()-1;i<j;i++,j--){
        if(str[i]!=str[j]){
            flag++;
        }
    }
    if(flag==0){
        palindrome = true;
    }
    else{
        palindrome = false;
    }
return palindrome;
}

int main(){
    string word;
    cout<<"Please enter a word: ";
    getline(cin,word);
    bool palindrome;
    palindrome = isPalindrome(word);
    if(palindrome){
        cout<<word<<" is a palindrome";
    }
    else{
        cout<<word<<" is not a palindrome";
    }
    return 0;
}