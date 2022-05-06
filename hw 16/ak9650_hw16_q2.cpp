//This program is written by ak9650, Ashwin K Raghu

#include<iostream>
#include<vector>

using namespace std;

template<class T>
class Queue{
    private:
        vector<T> q;
        int idx_start, idx_end;
    
    public:
        Queue() : idx_start(0), idx_end(0) {}

        bool empty() const{
            return q.empty();
        }

        int size() const{
            return q.size() - idx_start;
        }

        T front() const{
            if(q.empty()){
                cout<<"Cannot fetch front: Queue empty!"<<endl<<"Exiting...";
                exit(1);
            }
            return q[idx_start];
        }

        T back() const{
            if(q.empty()){
                cout<<"Cannot fetch back: Queue empty!"<<endl<<"Exiting...";
                exit(1);
            }
            return q[idx_end];
        }

        void push(T element){
            q.push_back(element);
            idx_end = q.size() - 1;
        }

        void pop(){
            if(q.empty())
                cout<<"Cannot pop - queue empty!"<<endl;
            else{
                idx_start++;
                if(idx_end<idx_start){
                    q.clear();
                    idx_start = 0;
                    idx_end = 0;
                }
            }
        }

        void printQueue(){
            if(!q.empty()){
                for(int i=idx_start;i<=idx_end;i++){
                    cout<<q[i]<<" ";
                }
                cout<<endl;
            }
            else
                cout<<"Cannot print - queue empty!"<<endl;
        }
        
};

int main(){
    Queue<int> queueObj;

    cout<<"Pushing elements 3,5,2 to the queue.";
    queueObj.push(3);
    queueObj.push(5);
    queueObj.push(2);

    cout<<endl<<endl<<"Printing queue:"<<endl;
    queueObj.printQueue();
    cout<<endl;

    cout<<"Popping the front element";
    queueObj.pop();

    cout<<endl<<"Printing queue:"<<endl;
    queueObj.printQueue();
    cout<<endl;

    cout<<"Printing front element, back element and size of the queue:"<<endl;
    cout<<"Front: "<<queueObj.front()<<", Back: "<<queueObj.back()<<", Size: "<<queueObj.size();

    cout<<endl<<endl<<"Popping twice."<<endl<<endl;
    queueObj.pop();
    queueObj.pop();
    cout<<"Checking if the queue is empty and printing its size:"<<endl;
    if(queueObj.empty())
        cout<<"Queue empty. Size is "<<queueObj.size()<<".";
    else
        cout<<"Queue not empty. Size is "<<queueObj.size()<<".";
    return 0;
}