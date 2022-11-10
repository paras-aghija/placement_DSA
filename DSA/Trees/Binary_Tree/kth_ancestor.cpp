#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> solve(vector<int> v, int x){
	stack<int> s;
	int n = v.size();
	vector<int> ans(n);
	for(int i=n-1;i>=0;i--){
		while(!s.empty() and v[i]+x>s.top()) s.pop();
		ans[i] = (s.empty()) ? -1 : s.top();
        s.push(v[i]);
	}
	return ans;
}

int main(){
	
	FIO;
	int n,x;
	cin>>n>>x;
	vector<int> v(n);
	for(int &x : v) cin>>x;
	vector<int> ans = solve(v, x);
	for(int &x : ans) cout<<x<<" ";
	return 0;
}