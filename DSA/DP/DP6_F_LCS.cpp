// magneto_19
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	F LCS
	Link : https://atcoder.jp/contests/dp/tasks/dp_f

	dp(i,j) => length of lcs for strings a[i] -> a[n] and b[j] -> b[n]

	Recurrence relation :-

	dp(i,j) =  {

		1. if(a[i] == b[j]) => 1 + dp(i+1,j+1)
		2. else => max {

			1. dp(i+1,j)
			2. dp(i,j+1)

		}
	}

	Base Case :-





*/

vector<vector<int>> dp(3000, vector<int> (3000, -1));

string getLCS(string &s, string &t, int len) {
	string LCS;
	int i = 0, j = 0;
	while (len > 0) {
		if (s[i] == t[j]) {
			LCS.push_back(s[i]);
			i++;
			j++;
			len--;
		}
		else {
			if (dp[i + 1][j] > dp[i][j + 1]) {
				i++;
			}
			else {
				j++;
			}
		}
	}
	return LCS;
}

// Top DOwn
int lenLCS(string s, string t, int i, int j) {
	if (i >= s.length() or j >= t.length()) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s[i] == t[j]) {
		return dp[i][j] = 1 + lenLCS(s, t, i + 1, j + 1);
	}
	else {
		return dp[i][j] = max(lenLCS(s, t, i + 1, j), lenLCS(s, t, i, j + 1));
	}
}

void solve() {
	string s, t;
	cin >> s >> t;
	int len = lenLCS(s, t, 0, 0);
	cout << getLCS(s, t, len);
}

int main() {

	FIO;
	solve();

	return 0;
}