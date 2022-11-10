#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// Bitonic Array => first monotonically increasing then monotonically decreasing
// monotonic => arr[i+1]>arr[i] AND NOT arr[i+1]>=arr[i]
// bitonic array => can never become sorted

int peak(vector<int> v){
	int n = v.size();
	int s=0, e=n-1;
	while(s<=e){
		int mid = s + (e-s)/2;
		if(mid+1<=n and v[mid+1]>v[mid]) s=mid+1;
		else if(mid-1>=0 and v[mid-1]>v[mid]) e = mid-1;
		else return mid;
	}
	return -1;
}

int search(vector<int> v, int k){
	int n = v.size();
	int s=0, e=n-1;
	int p = peak(v);

	int x = lower_bound(v.begin(), v.begin()+p, k) - v.begin();
	int y = lower_bound(v.begin()+p, v.end(), k, greater<int>()) - v.begin();

	if(x!=p) return (v[x]==k) ? x : -1;
	if(y!=n) return (v[y]==k) ? y : -1;

	return -1;

}

int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) cin>>x;

	cout<<peak(v)<<endl;

	cout<<search(v, 6);

	return 0;
}