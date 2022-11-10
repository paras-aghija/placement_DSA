#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


int redundant(string v){
	stack<char> s;
	for(int i=0;i<v.length();i++){
		if(v[i]=='('){
			s.push(v[i]);
			continue;
		}
		else if(v[i]==')' or v[i] == '}' or v[i] ==']'){
			bool op = 0;
			char x = s.top()
			while(!s.emtpy() and (x!='(' or x!='{' or x!='[')){
				x = s.top()
				if(x=='+' or x=='-' or x=='*' or x=='/') op=1;
				s.pop();
			}
			x = s.top();
			if(x=='(' and v[i]==')')


		}
	}
}

int main(){
	
	FIO;
	string s;
	cin>>s;
	cout<<redundant(s);

	return 0;
}