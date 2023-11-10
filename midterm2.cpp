#include <string.h>
#include <iostream>
using namespace std;

class charNode {
private:
	char elem;
	charNode* next;

	friend class charLinkedList;
};

class charLinkedList {
public:
	charLinkedList();   		// constructor
	~charLinkedList();  		// destructor 
	bool empty() const;        // true of list is empty
	const char& front() const;	// returns front element
	void addFront(const char& e);   // adds new element on the front
	void removeFront();		// removes front element
	const int ListLength(charNode* CurrentNode) const;
	void display();
	void reverse();
private:
	charNode* head;
};

class LinkedStack {
public:
	LinkedStack();
	int size() const;
	bool empty() const;
	const char& top() const;
	void push(const char& elem);
	void pop();
	void display_stack();
	void Sreverse();
private:
	charLinkedList S; //including this requires the special constructor format
	int n;
};

bool charLinkedList::empty() const {
	return (head == NULL);
}

charLinkedList::charLinkedList() {

	head = NULL;

}

void charLinkedList::reverse() {///////////////////////////////////////reverse display function
	charNode* p = head;
	while (p != NULL) {
		cout << "'" << p->elem << "'";
		p = p->next;
	}
}

void charLinkedList::display() {/////////////////////////////////////// display function
	charLinkedList B;
	charNode* p = head;
	while (p!=NULL) {
		B.addFront(p->elem);
		p=p->next;
	}
	B.reverse();
}

charLinkedList :: ~charLinkedList() {

	while (!empty()) removeFront();
}

void charLinkedList::addFront(const char& e) {
	charNode* p;

	p = new charNode;
	p->elem = e;

	p->next = head;
	head = p;

}


void charLinkedList::removeFront() {
	charNode* p;

	if (head != NULL) {
		p = head;
		head = p->next;
		delete p;
	}
	else
		cout << "Warning: attempt to remove from an empty list" << endl;

}

const char& charLinkedList::front() const {//method returns first node

	if (head != NULL) {
		return head->elem;
	}
	else {
		cout << "Warning: the list is empty" << endl;
	}
}

const int charLinkedList::ListLength(charNode* CurrentNode) const {

	if (CurrentNode == NULL)
		return 0;
	else
		return 1 + ListLength(CurrentNode->next);

}




LinkedStack::LinkedStack() : S()/*this calls the S [charlinkedlist] constructor*/, n(0) { }//sets n to zero, will also want to call constructor for S, S is a charlinkedlist and will need it's own constructor

void LinkedStack::push(const char& elem) {

	S.addFront(elem);
	n++;            //number of values in the stack
}

void LinkedStack::pop() {

	S.removeFront();
	n--;
}

bool LinkedStack::empty() const {

	return S.empty();
}

int LinkedStack::size() const {
	return n;//num values in stack
}

const char& LinkedStack::top() const {

	return S.front();//needed to create new charlinkedlist method
}

void LinkedStack::display_stack() {
	S.display();
}

void LinkedStack::Sreverse() {
	S.reverse();
}

int main() {
	LinkedStack A;
	string s;
	cout << "Enter a string to reverse:" << endl;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		A.push(s.at(i));
	}
	A.display_stack();
	cout << endl;
	A.Sreverse();
}