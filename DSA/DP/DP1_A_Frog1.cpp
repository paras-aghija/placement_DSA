// magneto_19
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#define ll long long
/*

	A Frog - 1
	Link : https://atcoder.jp/contests/dp/tasks/dp_a
	Time Complexity = O(n)
	Space Complexity = O(n)

*/

void solve() {
	int n;
	cin >> n;
	vector<ll> v(n + 1), dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		ll op1 = abs(v[i] - v[i - 1]) + dp[i - 1];
		ll op2 = (i == 2) ? INT_MAX : abs(v[i] - v[i - 2]) + dp[i - 2];

		dp[i] = min(op1, op2);
	}
	cout << dp[n] << endl;

}

int main() {

	FIO;
	solve();


	return 0;
}