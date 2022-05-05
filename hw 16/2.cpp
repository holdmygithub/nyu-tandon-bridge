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
                cout<<"Queue empty!";
                exit(1);
            }
            return q[idx_start];
        }

        T back() const{
            if(q.empty()){
                cout<<"Queue empty!";
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
    Queue<int> intqueue;

    intqueue.push(0);
    intqueue.push(1);
    intqueue.push(2);
    intqueue.push(3);

    intqueue.printQueue();
    intqueue.pop();
    intqueue.pop();
    intqueue.pop();
    intqueue.printQueue();
    return 0;
}