#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// Brute force solution try every possible height => TC : O(N2)

// OPTIMIZATION => Next Greater Element

vector<int> nextSmallerElement(vector<int> &v, int n)
{
    // Write your code here.
    vector<int> ans(n, -1);
    stack<int> s;
    s.push(v[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() and v[i]<=s.top()) s.pop();
        ans[i] = (s.empty()) ? n-1 : s.top();
        s.push(v[i]);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &v, int n)
{
    // Write your code here.
    vector<int> ans(n, -1);
    stack<int> s;
    s.push(v[0]);
    for(int i=1;i<n;i++){
        while(!s.empty() and v[i]<=s.top()) s.pop();
        ans[i] = (s.empty()) ? 0 : s.top();
        s.push(v[i]);
    }
    return ans;
}

void solve() {
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) cin>>x;

	vector<int> left_small = prevSmallerElement(v,n);
	vector<int> right_small = nextSmallerElement(v,n);

	int ans = INT_MIN;
	for(int i=0;i<n;i++){
		int h = v[i];
		int w = right_small[i] - left_small[i] + 1;
		ans = max(ans, h*w);
	}
	cout<<ans<<endl;
}

int main(){
	
	FIO;
	solve();

	return 0;
}