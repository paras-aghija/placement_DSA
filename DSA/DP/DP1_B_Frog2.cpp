// magneto_19
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#define ll long long

/*

	B Frog-2
	Link : https://atcoder.jp/contests/dp/tasks/dp_b

*/
void solve() {
	int n, k;
	cin >> n >> k;
	vector<ll> v(n + 1), dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		ll cost = INT_MAX;
		for (int jump = 1; jump <= k; jump++) {
			if (i - jump <= 0) {
				break;
			}
			cost = min(cost, dp[i - jump] + abs(v[i] - v[i - jump]));
		}
		dp[i] = cost;
	}
	cout << dp[n] << endl;
}

int main() {

	FIO;
	solve();

	return 0;
}