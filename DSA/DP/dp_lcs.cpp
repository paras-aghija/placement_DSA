#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

given two strings find longest common subsequence

a = "ABCD"
b = "ABEDG"

lcs : "ABD"

*/

int bruteForce(string  a, string b, int i, int j) {
	// Base case
	if (i == a.length() or j == b.length()) {
		return 0;
	}

	// rec case
	if (a[i] == b[j]) {
		return 1 + bruteForce(a, b, i + 1, j + 1);
	}
	int op1 = bruteForce(a, b, i + 1, j);
	int op2 = bruteForce(a, b, i, j + 1);
	return max(op1, op2);
}


int topDown(string  a, string b, int i, int j, vector<vector<int>> &dp) {
	// Base case
	if (i == a.length() or j == b.length()) {
		return 0;
	}

	// lookup
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	// rec case
	if (a[i] == b[j]) {
		return dp[i][j] = 1 + topDown(a, b, i + 1, j + 1, dp);
	}
	int op1 = topDown(a, b, i + 1, j, dp);
	int op2 = topDown(a, b, i, j + 1, dp);
	return dp[i][j] = max(op1, op2);
}

int main() {

	FIO;
	string a = "ABCD";
	string b = "ABEDG";
	int n = a.length();
	int m = b.length();
	vector<vector<int>> dp(n, vector<int> (m, -1));
	cout << topDown(a, b, 0, 0, dp);
	return 0;
}