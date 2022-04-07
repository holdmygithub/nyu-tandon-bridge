//Program written by ak9650, Ashwin K Raghu
#include<iostream>
using namespace std;

const int ALPHABETS_SIZE = 26;
const char small_a = 'a', small_z = 'z', capital_a = 'A', capital_z = 'Z';
const char whitespace = ' ', comma=',', fullstop = '.';

bool isDelimiter(char a){
    return (a==whitespace|| a==comma || a==fullstop);
}

int wordsAndWordCount(int count_alphabets[],string line){
    char prev_char = whitespace;
    int wordCount=0;
    bool alpha;

    for(int i=0;i<line.length();i++){
        if(line[i]>=small_a && line[i]<=small_z){
            count_alphabets[line[i]-small_a]++;
            alpha=true;
        }

        else if(line[i]>=capital_a && line[i]<=capital_z){
            count_alphabets[line[i]-capital_a]++;
            alpha=true;
        }
        else{
            alpha = false;
        }

        if(alpha && isDelimiter(prev_char))
            wordCount++;
        prev_char = line[i];
    }
return wordCount;
}

int main(){
    string line;
    int count_alphabets[ALPHABETS_SIZE] = {0},wordcount;

    cout<<"Please enter a line of text:"<<endl;
    getline(cin,line);
    wordcount = wordsAndWordCount(count_alphabets, line);
    cout<<wordcount<<"\t"<<"words"<<endl;
    for(int i=0;i<ALPHABETS_SIZE;i++){
        if(count_alphabets[i]>0)
            cout<<count_alphabets[i]<<"\t"<<(char)(i+small_a)<<endl;
    }
    return 0;

}