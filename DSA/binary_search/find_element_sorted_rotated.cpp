#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int solve(vector<int> v, int k){
	int n=v.size();
	int s=0, e=n-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(v[mid]==k) return mid;
		if(v[mid]>v[0] and k>=v[0] and k<v[mid]) e = mid-1;
		else s = mid+1;
	}
	return -1;
}

int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) cin>>x;
	int k;
	cin>>k;
	cout<<solve(v,  k);

	return 0;
}