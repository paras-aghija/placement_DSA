#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void printv(vector<int> v){
	for(int x : v) cout<<x<<" ";
	cout<<endl;
}

vector<int> left_smaller(vector<int> v){
	stack<int> s;
	vector<int> ans(v.size());
	s.push(0);
	ans[0] = -1;

	for(int i=1;i<v.size();i++){
		while(!s.empty() and v[i]<=v[s.top()]) s.pop();
		ans[i] = (s.empty()) ? -1 : s.top();
		s.push(i);
	}
	printv(ans);
	return ans;
}

vector<int> right_smaller(vector<int> v){
	int n = v.size();
	stack<int> s;
	vector<int> ans(v.size());
	s.push(n-1);
	ans[n-1] = n;
	for(int i=n-2;i>=0;i--){
		while(!s.empty() and v[i]<=v[s.top()]) s.pop();
		ans[i] = (s.empty()) ? n : s.top();
		s.push(i);
	}
	printv(ans);
	return ans;
}

int largestRectangleArea(vector<int>& heights) {
	vector<int> ls = left_smaller(heights);
	vector<int> rs = right_smaller(heights);
	int ans = 0;
	for(int i=0;i<heights.size();i++){
		ans = max(heights[i]*(rs[i]-ls[i]-1), ans);
	}
	return ans;
}

int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) cin>>x;
	int ans = largestRectangleArea(v);
	cout<<ans<<endl;

	return 0;
}