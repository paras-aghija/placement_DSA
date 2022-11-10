#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Codeforces problem 768C: Jon Snow and his Favourite Number
*/

vector<int> f(1500, 0);

int main() {

	FIO;
	int n, k, x;
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		f[t]++;
	}
	while (k--) {
		int l = 0;
		vector<int> s = f;
		for (int i = 0; i < 1500; i++) {
			if (f[i] > 0) {
				int curr = i ^ x;
				int cval = f[i] / 2;
				if (l == 0) {
					cval += f[i] & 1;
				}
				s[i] = s[i] - cval;
				s[curr] += cval;
				l ^= f[i] & 1;
			}
		}
		f = s;
	}
	int mine = INT_MAX, maxe = INT_MIN;

	for (int i = 0; i < 1500; i++) {
		if (f[i] == 0) continue;
		mine = min(mine, i);
		maxe = max(maxe, i);
	}
	cout << maxe << " " << mine << endl;
	return 0;
}