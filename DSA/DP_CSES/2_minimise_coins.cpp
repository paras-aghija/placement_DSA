#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
	
	FIO;
	int n,t;
	cin>>n>>t;
	vector<int> v(n);
	for(int &x : v) cin>>x;
	int mod = 1e9+7;
	vector<int> dp(t+1, INT_MAX-1);
	dp[0]=0;
	for(int x : v){
		for(int i=x;i<=t;i++){
			dp[i] = min(dp[i], dp[i-x]) + 1;
			dp[i]%=mod;
		}
	}

	if(dp[t]==INT_MAX%mod) cout<<-1;
	else cout<<dp[t];

	return 0;
}