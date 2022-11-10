#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void printv(vector<int> v){
	for(int x : v) cout<<x<<" ";
	cout<<endl;
}

void solve(vector<int> &v, int r, int c){
	int n = v.size();
	vector<int> z(n), o(n);
	z[0]=v[0]==0;
	o[0]=v[0]==1;
	for(int i=1;i<n;i++){
		o[i] = o[i-1] + v[i];
		z[i] = z[i-1] + !v[i];
	}
	int s = r+c;
	vector<int> dp(n);
	dp[0]=0;
	for(int i=1;i<n;i++){
		dp[i] = dp[i-1];
		if(o[i]!=0 and (double)z[i]/o[i]==(double)r/c) dp[i]++;
		if(i>s){
			int ii = i-s;
			int x = z[i]-z[ii];
			int y = o[i]-o[ii];
			if(x>0 and y>0 and (double)x/y==(double)r/c) dp[i]++;
		}
		if(i>=r and (double)z[i-r]/o[i-r]==(double)r/c) dp[i] += dp[i-r];
		if(i>=c and (double)z[i-c]/o[i-c]==(double)r/c) dp[i] += dp[i-c];
		if(i>=s and (double)z[i-s]/o[i-s]==(double)r/c) dp[i] += dp[i-s];
		// cout<<dp[i]<<" ";
	}
	// cout<<endl;
	cout<<dp[n-1]<<endl;
	return;
}

int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) cin>>x;
	int r, c;
	cin>>r>>c;
	solve(v, r, c);	

	return 0;
}