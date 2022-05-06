//This program is written by ak9650, Ashwin K Raghu

#include<iostream>
#include<string>
#include<stack>
#include<fstream>

using namespace std;

const char BEGIN='b';

void openFile(fstream& stream, const string file){
	stream.open(file,ios::in);
	if(!stream){
		cout<<file<<": File opening failed.";
		exit(1);
	}
}

void closeFile(fstream& stream){ stream.close();}

bool symbolBalanceChecker(fstream& inFile){
    stack<char> stackObj;
    string inp;
    char top_element;
    while(inFile>>inp){
        if(inp=="BEGIN" || inp=="begin"){
            stackObj.push(BEGIN);
        }
        else if(inp=="END." || inp=="end." || inp =="end" || inp == "END" || inp =="END;" || inp == "end;"){
            if(stackObj.empty())
                return false;
            else{
                top_element = stackObj.top();
                stackObj.pop();
                if(top_element!=BEGIN)
                    return false;
            }
        }
        else{
            for(char c:inp){
                if(c=='(' || c=='[' || c=='{'){
                    stackObj.push(c);
                }
                else if(c==')' || c==']' || c=='}'){
                    if(stackObj.empty())
                        return false;
                    else if(c==')'){
                        top_element = stackObj.top();
                        stackObj.pop();
                        if(top_element!='(')
                            return false;
                    }
                    else if(c==']'){
                        top_element = stackObj.top();
                        stackObj.pop();
                        if(top_element!='[')
                            return false;
                    }
                    else if(c=='}'){
                        top_element = stackObj.top();
                        stackObj.pop();
                        if(top_element!='{')
                            return false;
                    }
                }
            }
        }
    }
if(stackObj.empty())
    return true;

return false;
}
int main(){
    string filename;
    fstream inFile;
    bool balanced;

    cout<<"Symbol Balance Checker for Pascal Programming Language:"<<endl<<"Enter filename: ";
    cin>>filename;

    openFile(inFile,filename);
    balanced = symbolBalanceChecker(inFile);
    closeFile(inFile);

    if(balanced){
        cout<<"Symbols match (Balanced).";
    }
    else{
        cout<<"Symbols do not match (Unbalanced).";
    }

    return 0;
}

