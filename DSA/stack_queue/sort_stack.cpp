#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void sortStack(stack<int> &s)
{
	// Write your code here
    if(s.size()==1) return;
    
    int t = s.top();
    s.pop();
    sortStack(s);
    stack<int> h;
    while(!s.empty() and s.top()>t){
        h.push(s.top());
        s.pop();
    }
    s.push(t);
    while(!h.empty()){
        s.push(h.top());
        h.pop();
    }
}

int main(){
	
	FIO;
	stack<int> s;
	s.push(5);
	s.push(-2);
	s.push(9);
	s.push(-7);
	s.push(3);

	sortStack(s);

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}