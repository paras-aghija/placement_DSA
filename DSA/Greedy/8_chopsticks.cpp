#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

void solve() {
	ll n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] - v[i - 1] <= x) {
			ans++;
			i++;
		}
	}
	cout << ans << endl;
}

int main() {

	FIO;
	solve();

	return 0;
}