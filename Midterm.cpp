#include <iostream>
#include <string.h>
using namespace std;

class Node {
private:
	string name;
	float gpa;
	Node* next;
	Node* previous;
	friend class LinkedList;
};

class LinkedList {
public:
	void add(string s, float g);//decreasing order
	LinkedList();
	~LinkedList();
	void remove(float g);//all nodes with g as gpa
	void display();
	bool empty() const;
private:
	Node* header=new Node;
	Node* trailer=new Node;
};


	bool LinkedList::empty() const {
		return (header->next==trailer);
	}

	LinkedList::LinkedList() {

		header->previous = NULL;
		header->next = trailer;
		trailer->previous = header;
		trailer->next = NULL;
	}

	LinkedList::~LinkedList(){
		if (empty()) {
			cout << "Empty" << endl;
		}
		else {
			while (!empty()) {
				Node* p = header->next;
				header->next = p->next;
				delete p;
			}
		}
	}

	void LinkedList::add(string s, float g) {
		Node* p = new Node;
		p->name = s;
		p->gpa = g;
		if (empty()) {
			header->next = p;
			p->previous = header;
			p->next = trailer;
			trailer->previous = p;
		}
		else {
				Node* t = header->next;
				while (t != trailer) {
								if (t->gpa >= p->gpa) {
									t = t->next;
								}
								else {
									t->previous->next = p;
									p->previous = t->previous;
									p->next = t;
									t->previous = p;
									return;
								}
							}
							if (t == trailer) {
								trailer->previous = p;
								t->next = p;
								p->next = trailer;
								p->previous = t;
							}
						}
			
			
			

	}

	void LinkedList::remove(float g) {
		Node* p = header->next;
		if (!empty()) {
			while (p!=trailer) {
				if (p->gpa == g) {
					Node* old = p;
					p = p->next;
					old->previous->next = p;
					p->previous = old->previous;
					delete old;
				}
				else {
					p = p->next;
				}
			}
		}
		else {
			cout << "Empty" << endl;
		}
	}

	void LinkedList::display(){
		if (empty()) {
			cout << "Nothing to display" << endl;
		}
		else {
			Node* p = header->next;
			while (p != trailer) {
				cout << "Name: " << p->name << " GPA: " << p->gpa << endl;
				p = p->next;
			}
		}
	}

	int main() {
		LinkedList A;
		string n;
		float g=0;
		while (g >= 0) {
			cout << "Enter name:" << endl;
			cin >> n;
			cout << endl<<"Enter gpa [will terminate if a negative number]:"<<endl;
			cin >> g;
			cout << endl;
			A.add(n, g);
		}
		A.display();
		cout << endl << "Please enter a gpa you'd like to remove from the list:" << endl;
		cin >> g;
		cout << endl;
		A.remove(g);
		A.display();
		

	}