/*
-----------------
| M A G N E T O |
-----------------
*/

#include<bits/stdc++.h>
using namespace std;
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

void printv(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	// printv(v);
	do {
		printv(v);
	} while (next_permutation(all(v)));
}

signed main() {
	FIO;
	solve();
	return 0;
}