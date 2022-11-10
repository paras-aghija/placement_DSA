#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = INT_MIN;
        for(int i=0;i<n;i++){
            int idx = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
            dp[idx] = v[i];
        }
        for(int i=1;i<=n;i++){
            if(dp[i]==INT_MAX) return i-1;
        }
        return n;
    }
};

int main(){
	
	FIO;
	

	return 0;
}