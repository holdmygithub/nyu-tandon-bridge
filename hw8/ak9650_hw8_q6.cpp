// Program written by ak9650, ashwin k raghu
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

string replaceWithX(string line,int pos, int pos2){
    for(int i=pos;i<pos2;i++){
            line[i] = 'x';
    }
    return line;
}
string checkIntegerPart(string line,int pos,int pos2){
    int flag=0;
    const char NINE = '9', ZERO = '0';
    string substr = line.substr(pos,pos2-pos);
    for(int i=0;i<substr.length();i++){
        if(substr[i] > NINE || substr[i] < ZERO){
            flag++;
        }
    }
    if(flag==0){
        line = replaceWithX(line,pos,pos2);
    }
return line;
}

int main(){
    string line,substr;
    int pos,pos2;
    cout<<"Please enter a line of text: "<<endl;
    getline(cin,line);
    pos = 0;
    while(pos<(int)line.length()){
        pos2 = line.find(' ',pos);
        if(pos2==string::npos){
            pos2=line.length();
        }
        line = checkIntegerPart(line,pos,pos2);
        pos = pos2+1;
    }
    cout<<line;
    return 0;
}