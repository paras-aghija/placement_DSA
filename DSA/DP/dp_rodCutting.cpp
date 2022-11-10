#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

Length :-
N = 8

Example 1 :-

length | 1   2   3   4   5   6   7   8
-------------------------------------------
price  | 1   5   8   9   10  17  17  20

Max Profit : 22


Example 2 :-

length | 1   2   3   4   5   6   7   8
-------------------------------------------
price  | 3   5   8   9   10  17  17  20

Max Profit : 34

*/

int recursive(int n, vector<int> prices) {
	if (n <= 0) {
		return 0;
	}
	int ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		int cut = i + 1;
		int current_ans = prices[i] + recursive(n - cut, prices);
		ans = max(ans, current_ans);
	}
	return ans;
}

int bottomUp(int n, vector<int> prices) {
	vector<int> dp(n + 1);
	dp[0] = 0;
	for (int len = 1; len <= n; len++) {
		dp[len] = INT_MIN;
		for (int i = 0; i < len; i++) {
			int cut = i + 1;
			int current_ans = prices[i] + dp[len - cut];
			dp[len] = max(dp[len], current_ans);
		}
	}
	return dp[n];
}

int main() {

	FIO;
	int n;
	cin >> n;
	vector<int> prices(n);
	for (int i = 0; i < n; i++) {
		cin >> prices[i];
	}
	cout << bottomUp(n, prices);


	return 0;
}