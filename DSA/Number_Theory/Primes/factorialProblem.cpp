#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
using namespace std;
/*

	Given two integers n and k find maximum value of x such that
	n! % k^x = 0

	i.e n! is completely divisible by k^x

	sample input

	5 2
	5! = 120 =  1 x 2 x 3 x 4 x 5
	for 2^x to be completely divisible by 5! we need to find the highest
	power of 2 in 5!

	K = (p1k1)*(p2k2)*(p3k3)

	No. of occurences of 5 in n! =  [n/5]+[n/25]+[n/125]

*/

void solve() {
	int n, k;
	cin >> n >> k;
	int ans = INT_MAX;

	// find the factors of k
	for (int i = 2; i * i <= k; i++) {
		if (k % i == 0) {
			int occ = 0;
			while (k % i == 0) {
				k /= i;
				occ++;
			}

			// also find power of i in n! side by side
			int cnt = 0;
			int p = i;
			while (p <= n) {
				cnt += (n / p);
				p *= i;
			}
			// calculate ans
			ans = min(ans, cnt / occ);
		}
	}
	if (k > 1) {
		// this is a prime factor with power 1
		int occ = 1;
		int cnt = 0;
		int p = k;
		while (p <= n) {
			cnt += (n / p);
			p *= k;
		}
		ans = min(ans, cnt / occ);
	}
	if (ans == INT_MAX) {ans = 0;}
	cout << ans << endl;
}

int32_t main() {

	FIO;
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}