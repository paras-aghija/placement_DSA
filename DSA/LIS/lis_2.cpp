#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	DP-2 Method

	dp[i] => element at which the subsequence of length i ends

	in our example
	array => [1,5,2,3,4,9,6,10]
	dp-1  => [1,2,2,3,4,5,5,6]

	dp[5] = 9 or 6
	we will take the smaller ending for a perticular length

	arr => [1,5,2,4,6]
			0 1 2 3 4 5
	dp  => [_,1,2,4,6,_]

*/


int lis(vector<int> a) {

	int n = a.size();
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = INT_MIN;

	for (int i = 0; i < n; i++) {
		for (int length = 0; length < n; length++) {
			if (dp[length] < a[i] and a[i] < dp[length + 1]) {
				dp[length + 1] = a[i];
			}
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