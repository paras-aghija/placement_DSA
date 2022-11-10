#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
const int mod = 1e9 + 7;
using namespace std;

int n, m;
vector<vector<int>> dp(1002, vector<int> (1002, 0));

signed main() {

	FIO;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char t;
			cin >> t;
			if (t == '#') {
				dp[i][j] = -1;
			}
		}
	}

	dp[n][m] = 1;
	for (int i = n; i > 0; i--) {
		for (int j = m; j > 0; j--) {
			if (dp[i][j] == -1) {continue;}
			if (dp[i + 1][j] != -1) {dp[i][j] += dp[i + 1][j];}
			dp[i][j] %= mod;
			if (dp[i][j + 1] != -1) {dp[i][j] += dp[i][j + 1];}
			dp[i][j] %= mod;
		}
	}
	cout << dp[1][1];
	return 0;
}