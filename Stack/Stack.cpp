#include<iostream>
using namespace std;
class stack{
	private:
		int data;
		stack *link;
	public:
		stack *top;
		stack(){
			data=0;
			link=nullptr;
			top=nullptr;
		}
		stack(int data){
			this->data=data;
			link=nullptr;
			top=nullptr;
		}
		stack(stack *n){
			this->data=n->data;
			this->link=n->link;
			this->top=n->top;
		}
		int getData(){
			return data;
		}
		void setData(int data){
			this->data=data;
		}
		stack* getLink(){
			return link;
		}
		void setLink(stack *l){
			this->link=l;
		}
		void push(int);
		void pop();
		void print();
};
void stack::push(int data){
	stack *n=new stack(data);
	n->setLink(top);
	top=n;
}
void stack::pop(){
	if(top==nullptr) return;
	stack *temp=new stack(top);
	top=top->getLink();
	delete temp;
}
void stack::print(){
	if(top==nullptr) {
		cout << "Empty stack" << endl;
		return;
	}
	stack *temp=new stack(top);
	while(temp!=NULL){
		cout << temp->data << "->";
		temp=temp->link;
	}
	cout << "Null" << endl;
}
int main(){
	stack *n1=new stack();
	n1->push(102);
	n1->push(7);
	n1->push(741);
	n1->pop();
	n1->pop();
	n1->print();
	return 0;
}
