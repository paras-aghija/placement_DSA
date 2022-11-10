#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

string simplifyPath(string path){
	istringstream iss(path);
	stack<string> s;
	string token;
	while(getline(iss, token, '/')){
		if(token==".") continue;
		else if(token==".."){
			if(!s.empty()) s.pop();
			continue;
		}
		if(token.length()) s.push(token);
	}
	
	string ans = "";
	while(!s.empty()){
		ans += s.top()+'/';
		s.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	
	FIO;
	string s;
	cin>>s;
	cout<<simplifyPath(s);	

	return 0;
}