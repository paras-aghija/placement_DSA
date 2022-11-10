#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Denominations : [1,2,5,10,20,50,100,200,500,2000]
	N = 137 Rs
	Use min coins/notes to obtain N

	Greedy Approach : 100 + 20 + 10 + 5 + 2

	But for Denomination [1,7,10]
	N = 15

	Greedy Approach : 10 + 1 + 1 + 1 + 1 + 1 (6 coins)
	Ans : 7 + 7 + 1 (3 coins)

	Therefore greedy approach fails

*/

void printv(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int recursive(int n, vector<int> &d) {
	if (n == 0) {
		return 0;
	}
	int ans = INT_MAX;
	for (auto i : d) {
		if (n - i >= 0) {
			ans = min(ans, recursive(n - i, d));
		}
	}
	return 1 + ans;

}

vector<int> dp(100);
int bottom_up(int n, vector<int> &d) {
	for (int i = 1; i <= n; i++) {
		int m = INT_MAX;
		for (auto j : d) {
			if (i - j < 0) {
				break;
			}
			m = min(m, dp[i - j]);
		}
		dp[i] = 1 + m;
	}
	// printv(dp);
	return dp[n];
}


int main() {

	FIO;
	vector<int> d{1, 7, 10};
	int n = 13;
	cout << recursive(n, d) << endl;
	cout << bottom_up(n, d);


	return 0;
}