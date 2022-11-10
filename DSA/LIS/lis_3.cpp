#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	DP - 3
	In dp-3 method it can be observed that dp array will
	strictly be increasing
	this monotonic order of the dp array
	therefore we can use binary search to find a position
	such that

		dp[pos] < a[i] < dp[pos+1]

	Time Complexity of this approach is O(nlogn)

*/

int lis(vector<int> a) {

	int n = a.size();
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = INT_MIN;

	for (int i = 0; i < n; i++) {
		int length = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
		if (dp[length - 1] < a[i] and a[i] < dp[length]) {
			dp[length] = a[i];
		}
	}
	int lis = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] != INT_MAX) {
			lis = i;
		}
	}
	return lis;

}

int main() {

	FIO;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << lis(v);


	return 0;
}