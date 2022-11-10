#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

class Queue{

	stack<int> ip, op;

public:

	void push(int x){
		ip.push(x);
	}

	int pop(){
		if(op.empty()){
			while(!ip.empty()){
				op.push(ip.top());
				ip.pop();
			}
		}
		int t = op.top();
		op.pop();
		return t;
	}

	int size(){
		return op.size()+ip.size();
	}

	bool empty(){
		return (op.empty() && ip.empty());
	}

	int front(){
		if(op.empty()){
			while(!ip.empty()){
				op.push(ip.top());
				ip.pop();
			}
		}
		return op.top();
	}

};

int main(){
	
	FIO;
	Queue Q;
	Q.push(1);
	Q.push(2);
	Q.push(3);

	cout<<Q.front()<<endl;
	cout<<Q.size()<<endl;

	Q.push(4);
	Q.push(5);

	cout<<Q.size()<<endl;

	cout<<Q.front()<<endl;
	Q.pop();
	cout<<Q.front()<<endl;
	Q.pop();
	Q.pop();
	cout<<Q.front()<<endl;
	cout<<Q.size()<<endl;

	return 0;
}