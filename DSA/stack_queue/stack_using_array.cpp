#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

class Stack
{
	vector<int> v;
	int t=-1;
	
public:
	Stack() : v(1000)
	{

	}

	void push(int x){
		v[++t] = x;
	}

	int pop(){
		return (t==-1) ? -1 : v[t--];
	}

	int size(){
		return t+1;
	}

	bool empty(){
		return t==-1;
	}

	int top(){
		return (t==-1) ? -1 : v[t];
	}


};

int main(){
  
  FIO;
  Stack S;
  S.push(1);
  S.push(2);
  S.push(3);
  cout<<S.top();
  S.pop();
  cout<<S.top();
  cout<<S.size();

  return 0;
}
