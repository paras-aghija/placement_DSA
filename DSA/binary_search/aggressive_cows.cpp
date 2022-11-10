#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


bool canPlace(vector<int> &v, int k, int n){
	// cout<<endl<<k<<"->"<<n<<"cows : ";
	int p = v[0];
	int ans = 1;
	for(int i=1;i<v.size();i++){
		// cout<<v[i]<<" ";
		if(v[i]-p>=k){

			ans++;
			if(ans>=n) return 1;
			p=v[i];
		}
	}
	// cout<<"false";
	return 0;
}

void solve(){
	int n, k;
	cin>>n>>k;
	vector<int> stalls(n);
	for(int i=0;i<n;i++) cin>>stalls[i];
	sort(stalls.begin(), stalls.end());

	int l=0, h=stalls[n-1];
	int ans = 0;
	while(l<=h){
		int mid = (l+h)>>1;
		if(!canPlace(stalls, mid, k)) h=mid-1;
		else {
			ans = mid;
			l=mid+1;
		}
	}
	cout<<ans<<endl;
}

int main(){
	
	FIO;
	int t;
	cin>>t;
	while(t--){
		solve();
	}

	return 0;
}