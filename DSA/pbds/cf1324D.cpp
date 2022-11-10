/*
-----------------
| M A G N E T O |
-----------------
*/

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define FIO 			ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int 			long long
#define ff 				first
#define ss 				second
#define sz(x)			((int)x.size())
#define all(x)	 		x.begin(), x.end()
#define pi 				3.14159265358979323846
#define pb 				push_back
#define gcd(a,b) 		__gcd((a),(b))
#define w(t) 			int t; cin>>t; while(t--)
#define endl			'\n'
const int MOD = 1e9 + 7;



typedef tree<pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        PBDS;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	PBDS s;
	int c, ans = 0;
	for (int i = 0; i < n; i++) {
		c = a[i] - b[i];
		ans += s.size() - s.order_of_key({ -c, 1e6});
		s.insert({c, i});
	}
	cout << ans << endl;

}

signed main() {
	FIO;
	solve();
	return 0;
}