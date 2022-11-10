#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define ld long double
using namespace std;


signed main() {

	FIO;
	int n;
	cin >> n;
	vector<ld> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	vector<vector<ld>> dp(n + 1, vector<ld> (n + 1, 0));
	dp[1][1] = v[1];
	ld f = 1;
	for (int i = 1; i <= n; i++) {
		f *= (1 - v[i]);
		dp[i][0] = f;
	}
	for (int i = 2; i <= n; i++) {
		for (int x = 1; x <= i; x++) {
			dp[i][x] = v[i] * dp[i - 1][x - 1] + (1 - v[i]) * dp[i - 1][x];
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		cout << dp[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }
	ld ans = 0;
	for (int x = n; x > n / 2; x--) {
		ans += dp[n][x];
	}
	cout << ans;


	return 0;
}