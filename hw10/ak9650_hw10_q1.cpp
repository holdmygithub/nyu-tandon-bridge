//Program written by ak9650, Ashwin K Raghu

#include<iostream>
#include<string>
using namespace std;

const char whitespace = ' ';

int wordsAndWordCount(string sentence){
    int prev = 0,next=0,count=0;
    while((prev<sentence.length()) && (next<sentence.length())){
        next = sentence.find(whitespace,prev);
        if(prev==next){
            prev++;
        }
        else{
            count++;
            prev = next;
        }
    }
    return count;
}

string* createWordsArray(string sentence, int& outWordsArrSize){
    int prev = 0,next=0,count=0;
    outWordsArrSize = wordsAndWordCount(sentence);
    string* stringArr = new string[outWordsArrSize];
    while((prev<sentence.length()) && (next<sentence.length())){
        next = sentence.find(whitespace,prev);
        if(next==string::npos){
            stringArr[count++] = sentence.substr(prev,string::npos);
        }
        else if(prev==next){
            prev++;
        }
        else{
            stringArr[count++] = sentence.substr(prev,next-prev);
            prev = next;
        }
    }
    return stringArr;
}

int main(){
    string sentence,*stringArr;
    int wordCount, outWordsArrSize = 0;
    cout<<"Please enter the string:"<<endl;
    getline(cin,sentence);
    stringArr = createWordsArray(sentence,outWordsArrSize);
    cout<<"Number of words:"<<endl<<outWordsArrSize<<endl;
    cout<<"Printing the array of words:"<<endl;
    for(int i=0;i<outWordsArrSize;i++){
        cout<<stringArr[i]<<endl;
    }
    delete[] stringArr;
    stringArr = nullptr;
    return 0;
}