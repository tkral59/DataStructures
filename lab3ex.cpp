#include <string>
#include <iostream>
using namespace std;

class SongNode{
	private:
	string title;
	string artist;
	int year;
	SongNode *next;
	friend class SongNodeList;
};

class SongNodeList{
	private:
		SongNode *head;
	public:
		void addNode(const string& t, const string& a, const int y);
		SongNodeList();
		~SongNodeList();
		void removeFront();
		void displayList(SongNode *p);
		void removeNode(const string& title);
		void display();
		//constructor
		//destructor
		friend class SongNode;
};

SongNodeList::SongNodeList(){
	head=NULL;
}
SongNodeList::~SongNodeList(){
	while(head!=NULL){
		removeFront();
	}
}
void SongNodeList::removeFront(){
	if(head!=NULL){
		SongNode *old=head;
		head=old->next;
		delete old;		
	}
	else{
		return;
	}
}
void SongNodeList::addNode(const string& t, const string& a, const int y){
	SongNode *p;  //new node
	SongNode *p1; //first pointer
	SongNode *p2;//second pointer (in front)
	
	p=new SongNode;
	p->title=t;
	p->artist=a;
	p->year=y;
	if (head == NULL) {
		head = p;
		p->next = NULL;
	}
	else {
	  if (p->title < head->title) { // if new title is less than the current head
		p->next = head;
		head = p;
	   }
	   else {	
		for (p1 = head, p2 = p1->next; p2 != NULL && p->title <= p2->title; p1 = p2, p2 = p2->next) ;     // search stops at the first node with a title
	                               // greater than the current song or the last
	                               // node of the list
			p1->next = p;
			p->next = p2;
	   }
	}	
}

void SongNodeList::removeNode(const string& title){
	SongNode *p, *p1, *p2;
	
	if (head == NULL) {   // empty list
	    cout << "Warning: list is empty" << endl;
	}
	else {
	  if (title == head->title) { // if new title is less than the current head
		p = head;
	head = head->next;
		delete p;
	   }
	   else {	
		for (p1 = head, p2 = p1->next; p2 != NULL && title < p2->title; p1 = p2, p2 = p2->next) ;    
									 // search stops at the first node with a title
	                               // greater than the current song or the last
	                               // node of the list
		if (p2 != NULL && title == p2->title) {
			p1->next = p2->next;
			delete p2;
	      }
	      else
			cout << "Warning: the title is not in the list" << endl;
	   }
	}	
}

void SongNodeList::displayList(SongNode *p){
	if(p==NULL){
		return;
	}
	else{
		cout<<p->title<<" "<<p->artist<<" "<<p->year<<endl;
		displayList(p->next);
		return;
	}
}

void SongNodeList::display(){
	displayList(head);
}


int main(){
	SongNodeList SL;
	string title;
	string author;
	int year;
	int size;
//	cout<<"Enter the amount of songs you'd like to add."<<endl;
//	cin>>size;
/*	for(int i=0; i<size;i++){
		cout<<"Enter song title:"<<endl;
		cin>>title;
		cout<<endl<<"Enter song artist"<<endl;
		cin>>author;
		cout<<endl<<"Enter song year"<<endl;
		cin>>year;
		cout<<endl;
		SL.addNode(title, author, year);	
	}*/
	
	SL.addNode("Upward","Post Malone", 2016);
	SL.addNode("Song2", "Beatles", 1999);
	SL.addNode("Tres", "Boom", 1890);
	SL.display();
	SL.addNode("Acd","Kidz Bop", 2005);
	SL.addNode("Chbb","Author", 2000);
	SL.addNode("BBB", "fjdksl", 5);
//	SL.display();
	cout<<endl;
//	SL.removeNode("BBB");
//	SL.display();
	cout<<endl;
	
	SL.removeNode("Not");
//	SL.display();
	
	//cin>>title;
	//...
}


