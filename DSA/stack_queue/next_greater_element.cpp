#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> nextGreater(vector<int> &v, int n) {
    // Write your code here
    stack<int> s;
        s.push(v[n-1]);
        vector<int> ans(n, -1);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() and v[i]>=s.top()) s.pop();
            ans[i] = (s.empty()) ? -1 : s.top();
            s.push(v[i]);
        }
        return ans;

}

void printv(vector<int> v){
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    
    FIO;
    vector<int> v = {4,12,5,3,1,2,5,3,1,2,4,6};
    vector<int> ans = nextGreater(v, v.size());
    printv(ans);

    return 0;
}