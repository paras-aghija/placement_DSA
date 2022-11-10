#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Ladder Problem

	Man has to climb ladder to the top. At each step he can go atmost k steps
	forward. Print the number of ways to reach top
*/

int topDown(int n, int k) {
	if (n == 0) {
		return 1;
	}
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		if (n - i < 0) {
			break;
		}
		ans += topDown(n - i, k);
	}
	return ans;
}

int bottomUp(int n, int k) {
	int dp[100] = {0};
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
			}
		}
	}
	return dp[n];
}

int optimised(int n, int k) {
	int dp[100] = {0};
	dp[0] = 1, dp[1] = 1;
	for (int i = 2; i <= k; i++) {
		dp[i] = 2 * dp[i - 1];
	}
	for (int i = k + 1; i <= n; i++) {
		dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
	}
	return dp[n];
}

int main() {

	FIO;
	int n, k;
	cin >> n >> k;
	cout << optimised(n, k);

	return 0;
}