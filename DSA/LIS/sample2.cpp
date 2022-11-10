#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int solve(vector<int> v, int k){
	sort(v.begin(), v.end());
	int s=v[0], ans=1;
	for(int x : v){
		if(x-s>k){
			s=x;
			ans++;
		}
	}
	return ans;
}

int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v)
		cin>>x;
	int k;
	cin>>k;
	cout<<solve(v, k);

	return 0;
}