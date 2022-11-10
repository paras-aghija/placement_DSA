#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	Given n number of activites and their starting and ending time
	Do as much activities as possible

	Greedy approach : pick activity that finishes earlier

*/

void solve() {
	int n;
	cin >> n;
	int st, et;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> st >> et;
		v[i] = {et, st};
	}
	sort(v.begin(), v.end());
	int ans = 1;
	int ce = v[0].first;
	for (int i = 1; i < n; i++) {
		if (v[i].second >= ce) {
			ans++;
			ce = v[i].first;
		}
	}
	cout << ans << endl;
}

int main() {

	FIO;
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}