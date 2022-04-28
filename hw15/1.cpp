#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Employee{
    private:
        int id_number,hours_worked;
        double hourly_pay_rate;
        string name;

    public:
    Employee(int id_num, double hpr, string name_employee) : id_number(id_num), hourly_pay_rate(hpr), name(name_employee), hours_worked(0){}

    int getId() const{
        return id_number;
    }

    int getHoursWorked() const{
        return hours_worked;
    }

    double getHourlyPayRate() const{
        return hourly_pay_rate;
    }

    string getName() const{
        return name;
    }
    void addEmployeeHours(int hrs){
        hours_worked+=hrs;
    }

};

template <class T>
class LList; //Pre-Definition to make Friend work in LListNode

template <class T>
class LListNode {
	T data;
	LListNode<T>* next;
	LListNode<T>* prev;
public:
	LListNode(const T& newdata = T(), LListNode<T>* newnext = nullptr, LListNode<T>* newprev = nullptr) :data(newdata), next(newnext), prev(newprev) {}
	friend class LList<T>;
};

template <class T>
class LList {
	LListNode<T>* head;
	LListNode<T>* tail;
	
public:
	LList();
	~LList();
	LList(const LList<T>& rhs);
	LList<T>& operator=(const LList<T>& rhs);

	void clear() { while (!isEmpty()) pop_front(); }
	void push_back(const T& data) { tail->prev = new LListNode<T>(data, tail, tail->prev); tail->prev->prev->next = tail->prev; }
	void push_front(const T& data) { head->next = new LListNode<T>(data, head->next, head);  head->next->next->prev = head->next; }
	T pop_back();
	T pop_front();
	int size();
	bool isEmpty() { return head->next == tail; }
};
template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
	if (this == &rhs)
		return *this;
	clear();
	LListNode<T>* ptr = rhs.head->next;
	while (ptr != rhs.tail) {
		push_back(ptr->data);
	}
	return *this;
}
template <class T>
int LList<T>::size() {
	LListNode<T>* ptr = head->next;
	int count = 0;
	while (ptr != tail) {
		count++;
		ptr = ptr->next;
	}
	return count;
}
template <class T>
T LList<T>::pop_back() {
	if (tail->prev == head) //empty list!
		return T(); //not sure what to do here?  User did something dumb.
	T retval = tail->prev->data;
	LListNode<T>* nodeToDelete = tail->prev;
	tail->prev = nodeToDelete->prev;
	nodeToDelete->prev->next = nodeToDelete->next;
	delete nodeToDelete;
	return retval;
}
template <class T>
T LList<T>::pop_front() {
	if (tail->prev == head) //empty list!
		return T(); //not sure what to do here?  User did something dumb.
	T retval = head->next->data;
	LListNode<T>* nodeToDelete = head->next;
	head->next = nodeToDelete->next;
	head->next->prev = head;
	delete nodeToDelete;
	return retval;
}
template <class T>
LList<T>::~LList() {
	clear();
	delete head;
	delete tail;
}
template <class T>
LList<T>::LList(const LList<T>& rhs) {
	head = new LListNode<T>();
	tail = new LListNode<T>();
	head->next = tail;
	tail->prev = head;
	*this = rhs; //call to the assignment operator!!!
}
template <class T>
LList<T>::LList() { //build two nodes, as "Dummies" for teh sake of making things easier
	head = new LListNode<T>();
	tail = new LListNode<T>();
	head->next = tail;
	tail->prev = head;
}

void openFile(fstream& stream, const string file){
	stream.open(file,ios::in);
	if(!stream){
		cout<<file<<": File opening failed";
		exit(1);
	}
}

int main(){
	string emp_file = "employees.txt", payroll_file = "payroll.txt";
	fstream inEmp, inPay;
	int emp_num;
	double emp_hrr;
	string emp_name;

	openFile(inEmp,emp_file);
	openFile(inPay,payroll_file);

	while(inEmp>>emp_num){
		inEmp>>emp_hrr;
		inEmp.ignore(9999,' ');
		getline(inEmp,emp_name);
		cout<<emp_num<<" "<<emp_hrr<<" "<<endl;
		cout<<emp_name<<endl;
	}





	return 0;
}