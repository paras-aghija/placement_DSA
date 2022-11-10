#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

class Solution {
public:
    
    int n, m;
    vector<vector<int>> v;
    int tg;
    int ans=INT_MAX;
    void solve(int row, int sum){
        if(row==m){
            ans = min(ans, abs(tg-sum));
            return;
        }
        for(int e : v[row]){
            solve(row+1, sum+e);
        }
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        v = mat;
        tg=target;
        n = v.size();
        m = v[0].size();
        solve(0, 0);
        return ans;
    }
};

int main(){
    
    FIO;
    

    return 0;
}