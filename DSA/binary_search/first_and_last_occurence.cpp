#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

//  2 4 10 10 10 18 18 20
// lower_bound => 1st element equal to or just greater than the element
// upper_bound => 1st element greater than element

void sol_stl(vector<int> v, int k){
	int x = lower_bound(v.begin(), v.end(), k) - v.begin();
	int y = upper_bound(v.begin(), v.end(), k) - v.begin();
	cout<<x<<" "<<y-1<<endl;
}

void solve(vector<int> v, int k){
	int s=0, e=v.size()-1;	
	int fo=-1;
	while(s<=e){
		int mid = s + (e-s)/2;
		if(v[mid]==k){
			fo = mid;
			e = mid-1;
		}
		else if(v[mid]<k) s = mid+1;
		else e = mid - 1;
	}

	s = 0, e = v.size()-1;
	int lo=-1;
	while(s<=e){
		int mid = s + (e-s)/2;
		if(v[mid]==k){
			lo = mid;
			s = mid+1;
		}
		else if(v[mid]<k) s = mid+1;
		else e = mid - 1;
	}
	cout<<fo<<" "<<lo<<endl;
}

int main(){
	
	FIO;
	int n ;
	cin>> n;
	vector<int> v(n);
	for(int &x : v) cin>>x;	
	int k;
	cin>>k;
	
	sol_stl(v, k);
	solve(v,k);

	return 0;
}

// Variation : Count element in sorted array -> upper_bound - lower_bound OR lo-fo+1