#include<iostream>
using namespace std;
class queue{
	private:
		int data;
		queue *link;
	public:
		queue *head;
		queue *tail;
		queue(){
			data=0;
			link=nullptr;
			head=nullptr;
			tail=nullptr;
		}
		queue(int data){
			this->data=data;
			link=nullptr;
			head=nullptr;
			tail=nullptr;
		}
		queue(queue *n){
			this->data=n->data;
			this->link=n->link;
			this->head=n->head;
			this->tail=n->tail;
		}
		int getData(){
			return data;
		}
		void setData(int data){
			this->data=data;
		}
		queue* getLink(){
			return link;
		}
		void setLink(queue *l){
			this->link=l;
		}
		void push(int);
		void pop();
		void print();
};
void queue::push(int data){
	queue *q=new queue(data);
	if(head==NULL){
		head=tail=q;
		return;
	}
	else{
		tail->setLink(q);
		tail=tail->getLink();
	}
}
void queue::pop(){
	if(head==nullptr) return;
 	queue *temp=new queue(head);
 	head=head->link;
 	delete temp;
}
void queue::print(){
	if(head==nullptr) {
		cout << "Empty queue" << endl;
		return;
	}
	queue *temp=new queue(head);
	while(temp!=NULL){
		cout << temp->data << "->";
		temp=temp->link;
	}
	cout << "Null" << endl;
}
int main(){
	queue *n1=new queue();
	n1->push(102);
	n1->push(7);
	n1->push(741);
	n1->pop();
	n1->push(8);
	n1->print();
	return 0;
}
