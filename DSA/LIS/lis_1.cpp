#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	LIS (Longest Increasing Subsequence)

	1. DP-1 	(standard)			O(N^2)
	2. DP-2 	(tricky)			O(N^2)
	3. DP-3		(Binary Search)		O(NlogN)
	4. DP-4		(Segment Tree)		O(NlogN)

	array = [1,5,2,3,4,9,6,10]
	LIS of the array => [1,2,3,4,6]

	DP-1 O(N^2)

	dp[i] = length of lis ending at ith index

	array => [1,5,2,3,4,9,6,10]
	dp 	  => [1,2,2,3,4,5,5,6]

	standing at a[i] we must find if we include it or not
	we need to know all the previous best endings
	for element a[i] we need to check elements to its left
	smaller than a[i] and which of them gives the best ending

	dp[i] = max(dp[j] where a[j]<a[i] and j<i)
*/

int lis(vector<int> a) {
	int n = a.size();
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		dp[i] = 1; // every element can end at length 1
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	return *max_element(dp.begin(), dp.end());
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