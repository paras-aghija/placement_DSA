#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Brute Force : n^3

	Prefix Sum : n^2

	DP Solutiohn : n

*/


// dp based solution
int maxSum(int a[], int n) {
	int dp[100] = {0};
	dp[0] = a[0];
	int mssf = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = a[i] + dp[i - 1];
		if (dp[i] < a[i]) {
			dp[i] = a[i];
		}
		mssf = max(mssf, dp[i]);
	}
	return mssf;
}

// space optimised solution
// kadanes algorithm
int maxSum2(int a[], int n) {
	int cssf = a[0], mssf = a[0];
	for (int i = 1; i < n; i++) {
		cssf += a[i];
		if (cssf < a[i]) {
			cssf = a[i];
		}
		mssf = max(mssf, cssf);
	}
	return mssf;

}


int main() {

	FIO;
	int arr[] = { -3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxSum2(arr, n);

	return 0;
}