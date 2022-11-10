#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int floor(vector<int> v, int k){
	int n = v.size();
	int s=0, e=n-1;
	int ans = n, res;
	while(s<=e){
		int mid = s+(e-s)/2;
		if(v[mid]==k) return mid;
		else if(v[mid]<k){
			ans = mid;
			s = mid+1;
		} else{
			e = mid-1;
		}
	}
	return ans;
}

int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) cin>>x;

	int k;
	cin>>k;

	cout<<floor(v, k);

	return 0;
}