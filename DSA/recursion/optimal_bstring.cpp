#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
/*
	count number of binary strings possible with no consecutive ones
*/

int fun(int n, bool one) {
	if (n == 0) return 1;
	// placing 0 at nth spot
	int ans = fun(n - 1, true);
	if (one) {
		ans += fun(n - 1, false);
	}
	return ans;
}

int main() {

	FIO;
	int n;
	cin >> n;
	cout << fun(n, true);
	return 0;
}