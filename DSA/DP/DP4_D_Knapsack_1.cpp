#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#define ll long long

/*
	D Knapsack 1
	Link : https://atcoder.jp/contests/dp/tasks/dp_d

	Choose a subset and check if it fits in the knapsack
	maximise ans for each valid subset

	dp(n,w) => subset of items from 1-n and capacity is w producing largest val

	Recurrence relation :-

	dp(n,w) = max {

		1. dp(n-1,w)
		2. V[n] + dp(n-1,w-W[n])

	}

	Base Cases :-

	dp(0,x) = 0
	(w>0)


	Bottom Up Approach

	dp(i,w) => subset [i-1] is exactly w

	ith item => either choose it or leave it


	Recurrence relation :-

	dp(i,w) = max {

		1. V[i] + dp(i-1, w-W[i])
		2. dp(i-1,w)

	}

	Base Case :-

	1. dp(1,x) = 0 		if(x!=W[i])
	   dp(1,x) = V[1] 	if(x==W[i])


	final ans => dp[N][x] where { 0 < x < w }

	Time Complexity : O(n*w)
	Space Complexity : O(n*W)

*/

struct item {
	ll wt, val;
};

void solve() {
	ll n, W;
	cin >> n >> W;
	vector<item> ar(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> ar[i].wt >> ar[i].val;
	}
	vector<vector<ll>> dp(n + 1, vector<ll> (W + 1, 0));

	dp[1][ar[1].wt] = ar[1].val;

	for (int i = 2; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			dp[i][w] = dp[i - 1][w];
			if (ar[i].wt > w) {continue;}
			dp[i][w] = max(dp[i][w], ar[i].val + dp[i - 1][w - ar[i].wt]);
		}
	}

	cout << *max_element(dp[n].begin(), dp[n].end());

}

int main() {

	FIO;
	solve();

	return 0;
}