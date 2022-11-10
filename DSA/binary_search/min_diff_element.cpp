#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


/*

apply normal bs if element found then return mid
else after full execution of binary search\

high, low points to indices between which element must lie
therefor
ans = min(abs(v[high]-k), abs(v[low]-k))

*/


int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) cin>>x;
	int k;
	cin>>k;
	int a = lower_bound(v.begin(), v.end(), k) - v.begin();
	int diff = INT_MAX, ans;
	if(a<v.size()) {
		ans = a;
		diff = abs(k-v[a]);
	}
	if(a-1>=0 and abs(k-v[a-1])<diff) ans=a-1;
	cout<<ans<<endl;

	return 0;
}