#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// array => unsorted

int peak(vector<int> v){
	int n = v.size();
	int l=0, h=n-1;
	while(l<=h){
		int mid = l + (h-l)/2;
		if(mid-1>=0 and v[mid-1]>v[mid]) h=mid-1;
		else if(mid+1<n and v[mid+1]>v[mid]) l=mid+1;
		else return mid;
	}
	return -1;
}

int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) cin>>x;

	cout<<peak(v);

	return 0;
}