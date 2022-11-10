#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


class Stack{

	queue<int> q;

	

public:

	Stack(){

	}

	void push(int x){
		q.push(x);
		int t = q.size()-1;
		while(t--){
			q.push(q.front());
			q.pop();
		}
	}

	int pop(){
		if(q.empty()) return -1;
		int t = q.front();
		q.pop();
		return t;
	}

	int top(){
		return (q.empty()) ? -1 : q.front();
	}

	bool empty(){
		return q.empty();
	};

	int size(){
		return q.size();
	}

};

int main(){
  
  FIO;
  Stack S;
  cout<<S.empty()<<endl;
  S.push(1);
  S.push(2);
  S.push(3);
  cout<<S.top();
  S.pop();
  cout<<S.top();
  cout<<S.size()<<endl;
  cout<<S.empty();

  return 0;
}
