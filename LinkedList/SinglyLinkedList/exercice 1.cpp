#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node(){
			data=0;
			next=nullptr;	
		}
		node(int data){
			this->data=data;
			next=nullptr;	
		}
		node(node *n){
			this->data=n->data;
			this->next=n->next;	
		}
};

class pile{
	public:
		node *head;
		pile(){
			head=nullptr;
		}
		void empiler(int data){
			node *n=new node(data);
			n->next=head;
			head=n;
		}
		void depiler(){
			head=head->next;
		}
		void reverse();
};

class file{
	public:
		node *head;
		node *tail;
		file(){
			head=nullptr;
			tail=nullptr;
		}
		void enfiler(int data){
			node *n=new node(data);
			if(!head){
				head=n;
				tail=n;
			}
			else{
				tail->next=n;
				tail=tail->next;
			}
		}
		void defiler(){
			 
		}
};

void printP(pile *p){
	if(!p->head){
		cout << "Pile vide" << endl;
	}
	else{
		node *temp=new node(p->head);
		while(temp!=NULL){
			cout << temp->data << endl;
			temp=temp->next;
		}
	}
}

void printF(file *f){
	if(!f->head){
		cout << "File vide" << endl;
	}
	else{
		node *temp=new node(f->head);
		while(temp!=NULL){
			cout << temp->data << endl;
			temp=temp->next;
		}
	}
}

void pile::reverse(){
	file *f=new file(head);
	if(f==NULL){
		return;
	}
	else{
		node *temp=new node(head);
		while(temp!=NULL){
			f->enfiler(temp->data);
			temp=temp->next;
		}
		head=f->head;
	}
}

int main(){
	pile *p=new pile();
	p->empiler(18);
	p->empiler(45);
	p->empiler(715);
	printP(p);
	p->depiler();
	p->depiler();
	printP(p);
	p->PrintReverse(p,p->head);
	return 0;
}
