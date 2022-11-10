#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

string s;
int n;
int dp[1005][1005];

// top down
int lps(int i, int j) {
	if (i == j) {
		return dp[i][j] = 1;
	}
	if (i > j) { return 0;}
	if (s[i] == s[j]) {
		return dp[i][j] = 2 + lps(i + 1, j - 1);
	}
	else {
		int op1 = lps(i + 1, j);
		int op2 = lps(i, j - 1);
		return dp[i][j] = max(op1, op2);
	}
}

int longestPallindromeSubseq(string s) {
	return lps(0, n - 1);
}


// bottom up
int longestPallindromeSubseq2(string s) {
	memset(dp, 0, sizeof(dp));
	int n = s.length();
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			if (s[i] == s[j]) {
				dp[i][j] = 2 + dp[i + 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[0][n - 1];
}

int main() {

	FIO;
	cin >> s;
	n = s.length();
	cout << longestPallindromeSubseq2(s) << endl;

	return 0;
}