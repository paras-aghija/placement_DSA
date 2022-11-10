#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

bool isValid(vector<int> v, int n, int k){
	int i = 0;
	int csum = 0;
	int sn=0;
	while(i<v.size()){
		if(csum+v[i]<=n){
			csum += v[i++];
			continue;
		} else{
			sn++;
			csum=v[i++];
			if(sn==k) return 0;
		}
	}
	return sn==k-1 ? 1 : 0;
}

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) cin>>x;
	int k;
	cin>>k;
	int s = *max_element(v.begin(), v.end());
	int e = accumulate(v.begin(), v.end(), 0);
	int res = -1;
	while(s<=e){
		int mid = s + (e-s)/2;
		if(isValid(v, mid, k)){
			res = mid;
			e=mid-1;
		}
		else s = mid+1; 
	}
	cout<<res<<endl;
}

int main(){
	
	FIO;
	solve();

	return 0;
}