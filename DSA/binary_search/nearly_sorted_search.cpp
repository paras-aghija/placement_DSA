#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int solve(vector<int> v, int k){
	int n = v.size();
	int s=0, e=n-1;
	while(s<=e){
		int mid = s + (e-s)/2;
		if(v[mid]==k) return mid;
		else if(mid-1>=0 and v[mid-1]==k) return mid-1;
		else if(mid+1<n and v[mid+1]==k) return mid+1;
		else if(v[mid]>k) e=mid-2;
		else s = mid+2;
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
	cout<<solve(v, k);
	

	return 0;
}


/*

If element occures at ith index in sorted array 
then it can occure at i-1, i, i+1 in nearly sorted array

*/