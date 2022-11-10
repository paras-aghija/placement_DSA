#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int binary_search(vector<int> v, int key){
	int s=0, e=v.size()-1;
	while(s<=e){
		int mid = s + (e-s)/2;
		if(v[mid]==key) return mid;
		else if(v[mid]<key) s = mid+1;
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
	int k;
	cin>>k;
	cout<<binary_search(v, k);


	return 0;
}