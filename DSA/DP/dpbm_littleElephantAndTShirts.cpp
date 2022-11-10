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
int dp[1025][105];
vector<vector<int>> v(105);
int DONE;

void printv(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int fun(int pm, int tno) {
	// cout << pm << " " << tno << endl;
	if (pm == DONE) {
		// cout << "done" << endl;
		return 1;
	}
	if (tno == 101) {
		return 0;
	}

	if (dp[pm][tno] != -1) {
		return dp[pm][tno];
	}
	// ignoring current tno
	int ans = fun(pm, tno + 1);

	// allot the current tshirt to someone who have tshirt and is not alloted tshirt yet
	for (int person : v[tno]) {
		if ((pm & (1 << (person - 1))) == 0) {
			// cout << "alloting " << tno << " to " << person << endl;
			ans += fun(pm | (1 << (person - 1)), tno + 1);
			ans %= MOD;
		}
	}
	return dp[pm][tno] = ans;
}

void solve() {
	for (int i = 0; i <= 100; i++) {
		v[i].clear();
	}
	memset(dp, -1, sizeof(dp));
	cin >> n;
	DONE = (1 << n) - 1;
	cin.ignore();

	// input
	for (int p = 1; p <= n; p++) {
		vector<int> x;
		string s;
		getline(cin, s);
		// cout << s << endl;
		stringstream input_stream(s);
		int tno;
		while (input_stream >> tno) {
			v[tno].push_back(p);
		}
	}

	// for (int tno = 1; tno <= 100; tno++) {
	// 	if (v[tno].size() == 0) continue;
	// 	cout << tno << ": ";
	// 	printv(v[tno]);
	// }
	cout << fun(0, 1) << endl;

}

signed main() {
	FIO;
	w(t) {
		solve();
	}
	return 0;
}

/*
	Codechef : Little Elephant and Tshirts

	N :10
	T : 100

	Brute force: 100^10
	We will use reerse mapping
	Worst Case TC: 2^10*100*10 ~ 10^7 Acceptable TC

*/
