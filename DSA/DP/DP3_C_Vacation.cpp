// magneto_19
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	C Vacation
	Link : https://atcoder.jp/contests/dp/tasks/dp_c

	dp[n][0] : max possible happiness for days 1-n given that acivity A is done on day n
	dp[n][1] : max possible happiness for days 1-n given that acivity B is done on day n
	dp[n][2] : max possible happiness for days 1-n given that acivity C is done on day n

	Recurence relations:-

	dp[n][0] = a[n] + max(dp[n-1][1], dp[n-1][2])
	dp[n][1] = b[n] + max(dp[n-1][0], dp[n-1][2])
	dp[n][2] = c[n] + max(dp[n-1][1], dp[n-1][0])

	Base Cases

	dp[1][0] = a[1]
	dp[1][1] = b[1]
	dp[1][2] = c[1]

	Time Complexity : O(n)
	Space Complexity : O(n)
*/

struct activity {
	int a, b, c;
};

void solve() {
	int n;
	cin >> n;
	vector<activity> ar(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> ar[i].a >> ar[i].b >> ar[i].c;
	}
	int dp[n + 1][3];
	dp[1][0] = ar[1].a;
	dp[1][1] = ar[1].b;
	dp[1][2] = ar[1].c;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = ar[i].a + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = ar[i].b + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = ar[i].c + max(dp[i - 1][0], dp[i - 1][1]);
	}
	int ans = max(dp[n][0], max(dp[n][1], dp[n][2]));
	cout << ans;
}

int main() {

	FIO;
	solve();
	return 0;
}