#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {

	FIO;
	int t;
	cin >> t;
	int n, k;
	while (t--) {
		cin >> n >> k;

		int ans = INT_MAX;

		// Factorisation of k
		// p1,p2,p3 .... alogn with their powers

		for (int i = 2; i * i <= k; i++) {
			int occ = 0;
			if (k % i == 0) {
				while (k % i) {
					occ++;
					k /= i;
				}
				// find powers of i in n! side by side
				int cnt = 0;
				long long  p = i;
				while (p <= n) {
					cnt += n / p;
					p *= i;
				}
				ans = min(ans, cnt / occ);

			}
		}
		if (k > 1) {
			// occ of k = 1
			int cnt = 0;
			long long p = k;
			while (p <= n) {
				cnt += n / p;
				p *= k;
			}
			ans = min(ans, cnt);
		}
		if (ans == INT_MAX) {
			ans = 0;
		}
		cout << ans << endl;
	}

	return 0;
}