#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	SPOJ: GNYR09F

*/

int dp[105][105][2];

int solve(int n, int k, int first) {
	if (n == 0) return 0;
	if (n == 1) {
		if (k == 0) return 1;
		else return 0;
	}
	if (dp[n][k][first] != -1) {
		return dp[n][k][first];
	}

	int ans = -1;
	if (first == 1) {
		ans = solve(n - 1, k - 1, 1) + solve(n - 1, k, 0);
	}
	else {
		ans = solve(n - 1, k, 1) + solve(n - 1, k, 0);
	}
	return dp[n][k][first] = ans;
}

int main() {

	FIO;
	int t;
	cin >> t;
	while (t--) {
		int tno, n, k;
		cin >> tno >> n >> k;
		memset(dp, -1, sizeof(dp));
		int ans = solve(n, k, 0);
		ans += solve(n, k, 1);
		cout << tno << " " << ans << endl;
	}

	return 0;
}