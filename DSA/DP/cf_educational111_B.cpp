#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	int ans = n * a;
	if (b >= 0) {
		ans += n * b;
	}
	else {
		// b should be minimised
		int f = -1, t = 0;
		char sc = s[0];
		for (int i = 1; i < n; i++) {
			if (s[i] != sc and f == -1) {
				f = 1;
				t++;
			}
			else if (s[i] == sc) {
				f = -1;
			}
		}
		ans += (t + 1) * b;
	}
	cout << ans << endl;
}

signed main() {

	FIO;
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

/*
3
3 2 0
000
5 -2 5
11001
6 1 -4
111000

*/