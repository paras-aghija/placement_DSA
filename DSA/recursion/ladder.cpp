#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
vector<int> dp(100, -1);
int fun(int n) {
	if (n == 0) return 1;
	if (n < 0) return 0;
	if (dp[n] != -1) return dp[n];

	return dp[n] = fun(n - 1) + fun(n - 2) + fun(n - 3);
}

int main() {

	FIO;
	int n;
	// max jump allowed = 3
	cin >> n;
	cout << fun(n);
	return 0;
}