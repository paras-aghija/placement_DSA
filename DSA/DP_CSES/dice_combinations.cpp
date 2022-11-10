#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> dp(n+1);
	int mod = 1e9+7;
	dp[1]=dp[2]=dp[3]=dp[4]=dp[5]=dp[6]=1;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=i-6 and j>0;j--){
			dp[i] += dp[j];
			dp[i]%=mod;
		}
	}

	cout<<dp[n]<<endl;
	return 0;
}