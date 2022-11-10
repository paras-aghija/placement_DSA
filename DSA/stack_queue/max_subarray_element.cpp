#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// Naive solution : O(n2)
// Dequeu solution :O(n) O(k) space



int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) 
		cin>>x;

	int k;
	cin>>k;

	deque<int> dq;
	vector<int> ans;
	for(int i=0;i<v.size();i++){
		if(!dq.empty() and dq.front()==i-k) dq.pop_front();
		while(!dq.empty() and v[dq.back()]<v[i]) dq.pop_back();
		dq.push_back(i);
		if(i>=k-1) ans.push_back(v[dq.front()]);
	}

	for(int x:ans) cout<<x<<" ";



	return 0;
}