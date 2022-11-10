#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


vector<int> nextSmallerElement(vector<int> &v, int n)
{
    // Write your code here.
    vector<int> ans(n, -1);
    stack<int> s;
    s.push(v[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() and v[i]<=s.top()) s.pop();
        ans[i] = (s.empty()) ? -1 : s.top();
        s.push(v[i]);
    }
    return ans;
}


int main(){
    
    FIO;
    

    return 0;
}