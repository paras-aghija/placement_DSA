#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	wine prices = [2,3,5,1,4]
	p[i] = price of ith bottle
	In 1 year you can sell only one bottle that too only from extremes of the array
	prices of bottle increase every yr, in yth year price = p[i]*y



*/

int fun(int i, int j, int y, vector<int> &prices, vector<vector<int>> &dp) {
	if (i == j) {
		return prices[i] * y;
	}
	if (dp[i][j] != 0) {
		return dp[i][j];
	}
	return dp[i][j] = max(

	                      (prices[i] * y + fun(i + 1, j, y + 1, prices, dp)),
	                      (prices[j] * y + fun(i, j - 1, y + 1, prices, dp))
	                  );
}

void bottomUp(vector<int> prices) {
	// int n = prices.length();
	// vector<vector<int> > dp(n, vector<int> n);
	// traversing along diagonal is complex therefore topdown is easier
}

int main() {

	FIO;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<vector<int>> dp(n, vector<int> (n, 0));
	cout << fun(0, n - 1, 1, v, dp);


	return 0;
}