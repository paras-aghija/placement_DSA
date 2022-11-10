#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int bsDesc(vector<int> v, int k){
	int s = 0, e = v.size()-1;
	while(s<=e){
		int mid = s + (e-s)/2;
		if(v[mid]==k) return mid;
		if(v[mid]<k) e = mid-1;
		else s=mid+1;
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
	cout<<bsDesc(v, k);


	return 0;
}

/*
Variations : Not Known Ascending or descending
Changing mid on the basis of next or prev value to mid
check for size 1 
*/