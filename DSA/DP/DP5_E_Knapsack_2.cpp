#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#define ll long long

/*

	E Knapsack-2
	Link : https://atcoder.jp/contests/dp/tasks/dp_e

	select a subset of items from [1-n] s.t. sum of values is exactly v

	dp[i][v] => subset from [1,i] with sum of values exactly v
				then dp[i][v] represents minimum wt of possible selections

	suppose we got all done and we have dp[n][x] = [w1,w2,w3.....]
	find max value in this array <= W

	Recurrence Relation

	dp(i,v) = max {

		1. dp(i-1,v)
		2. w[i] + dp(i-1, v-val[i])
	}

	Base Cases :-

	dp(1,x) = w[1] if(x == val[1])
	dp(1,x) = infinity otherwise
	dp(1,0) = 0
*/

struct item {
	ll val, wt;
};

void solve() {
	int n, W;
	cin >> n >> W;
	vector<item> ar(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> ar[i].wt >> ar[i].val;
	}

	ll maxVal = n * 1000;
	vector<vector<ll>> dp(n + 1, vector<ll> (maxVal + 1));

	for (int i = 0; i <= maxVal; i++) {
		dp[1][i] = INT_MAX;
	}
	dp[1][ar[1].val] = ar[1].wt;
	dp[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		for (int v = 0; v <= maxVal; v++) {
			dp[i][v] = dp[i - 1][v];
			if (ar[i].val > v) {
				continue;
			}
			dp[i][v] = min(dp[i][v], ar[i].wt + dp[i - 1][v - ar[i].val]);
		}
	}

	ll ans;
	for (int x = 0; x <= maxVal; x++) {
		if (dp[n][x] <= W) {
			ans = x;
		}
	}
	cout << ans;
}

int main() {

	FIO;
	solve();

	return 0;
}