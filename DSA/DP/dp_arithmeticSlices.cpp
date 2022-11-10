#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	LEETCODE: Arithmetic Slices
*/

int n;
vector<int> dp(5001, 0);
// dp[i] = number of arithmetic slices ending at A[i]

void printv(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int numberOfArithmericSlices(vector<int> &A) {
	int ans = 0;
	for (int i = 2; i < n; i++ ) {
		// cout << (A[i] - A[i - 1]) << " " << (A[i - 1] - A[i - 2]) << endl;
		if ((A[i] - A[i - 1]) == (A[i - 1] - A[i - 2])) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = 0;
		}
		ans += dp[i];
	}
	return ans;
}

int main() {

	FIO;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << numberOfArithmericSlices(v);

	return 0;
}