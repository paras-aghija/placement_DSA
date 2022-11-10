#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// index of min element = no. of rotations

int solve(vector<int> v){
	int n = v.size();
	int s=0, e=n-1;
	while(s<=e){
		int mid = s + (e-s)/2;
		if(v[mid]<v[(mid+1)%n] and v[mid]<v[(mid-1+n)%n]) return mid;
		else if(v[mid]>v[0]) s = mid+1;
		else e = mid-1; 
	}
	return -1;
}

int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) cin>>x;
	cout<<solve(v);

	return 0;
}