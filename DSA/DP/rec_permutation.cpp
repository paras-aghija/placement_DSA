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

int n;
vector<int> permutation;
vector<vector<int>> permutations;
vector<bool> vis(1000, 0);

void fun() {
	if (permutation.size() == n) {
		permutations.pb(permutation);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		permutation.pb(i);
		fun();
		vis[i] = 0;
		permutation.pop_back();
	}
}


void printv(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

void solve() {
	cin >> n;
	fun();
	for (auto v : permutations) {
		printv(v);
	}
}

signed main() {
	FIO;
	solve();
	return 0;
}