class Solution {
public:
    int minimumDifference(vector<int>& v) {
        int sum1 = accumulate(v.begin(), v.end(), 0);
        int n = v.size();
        int sum = sum1/2;
        vector<bool> dp(sum+1, 0);
        dp[0]=1;
        for(int x : v){
            for(int i=sum;i>=x;i--){
                dp[i] = dp[i] || dp[i-x];
            }
        }
        int ans = 0;
        for(int i=0;i<=sum;i++){
          if(dp[i]) ans=i;  
        } 
        return sum1-2*ans;
    }
};