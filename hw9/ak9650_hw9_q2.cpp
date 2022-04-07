//Program written by ak9650, Ashwin K Raghu
#include<iostream>
#include<string>
using namespace std;

const int ALPHABETS_SIZE = 26;
const char small_a = 'a', small_z = 'z', capital_a = 'A', capital_z = 'Z';

bool checkAnagram(int count_alphabets1[],int count_alphabets2[]){
    int flag = 0;
    bool anagram;
    for(int i=0;i<ALPHABETS_SIZE;i++){
        if(count_alphabets1[i]!=count_alphabets2[i]){
            flag++;
        }
    }
return (flag==0);
}

void countAlphabetsString(int count_alphabets[],string line){
    for(int i=0;i<line.length();i++){
            if(line[i]>=small_a && line[i]<=small_z){
                count_alphabets[line[i]-small_a]++;
            }

            else if(line[i]>=capital_a && line[i]<=capital_z){
                count_alphabets[line[i]-capital_a]++;
            }

        }
}

int main(){
    string line1,line2;
    int count_alphabets1[ALPHABETS_SIZE] = {0},count_alphabets2[ALPHABETS_SIZE] = {0};
    bool is_anagram;

    cout<<"Please enter the first string:"<<endl;
    getline(cin,line1);
    cout<<"Please enter the second string:"<<endl;
    getline(cin,line2);

    countAlphabetsString(count_alphabets1,line1);
    countAlphabetsString(count_alphabets2,line2);
    is_anagram = checkAnagram(count_alphabets1,count_alphabets2);

    if(is_anagram){
        cout<<"Two strings are anagrams";
    }
    else{
        cout<<"Two strings are not anagrams";
    }

    return 0;
}