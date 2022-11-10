#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

struct node {
	int val;
	node *next;

	node(int x){
		val = x;
		next = NULL;
	}
};

class Queue{

	node *front, *back;
	int s;

public:

	Queue(){
		front = back = NULL;
		s = 0;
	}

	void push(int x){
		if(front==NULL){
			front = new node(x);
			back = front;
		} else{
			node *t = new node(x);
			back->next = t;
			back = t;
		}
		s++;
	}

	int pop(){
		if(front==NULL) return -1;
		node *t = front;
		if(front->next == NULL){
			front = NULL;
			back = NULL;
		} else {
			front = front->next;
		}
		int x = t->val;
		delete t;
		s--;
		return x;
	}

	int size(){
		return s;
	}

	bool empty(){
		return s==0;
	}

	int top(){
		return front->val;
	}

};

int main(){
	
	FIO;
	Queue Q;
	Q.push(1);
	Q.push(2);
	Q.push(3);

	cout<<Q.top()<<endl;
	cout<<Q.size()<<endl;

	Q.push(4);
	Q.push(5);

	cout<<Q.size()<<endl;

	cout<<Q.top()<<endl;
	Q.pop();
	cout<<Q.top()<<endl;
	Q.pop();
	Q.pop();
	cout<<Q.top()<<endl;
	cout<<Q.size()<<endl;

	return 0;
}