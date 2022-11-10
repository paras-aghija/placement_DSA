#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
const int mod = 1e9 + 7;
using namespace std;

int n;
vector<double> v(3000);
vector<vector<double>> dp(3000, vector<double> (3000, 0));
long double ans = 0;
vector<bool> cstate(3000);
void fun(int i) {
	if (i == n) {
		long double la = 1;
		int h = 0;
		for (int i = 0; i < n; i++) {
			if (cstate[i]) {
				la *= v[i];
				h++;
			}
			else {
				la *= 1 - v[i];
			}
		}
		if (h <= n / 2) {
			return;
		}
		// cout << la << endl;
		ans += la;
		return;
	}

	cstate[i] = true;
	fun(i + 1);
	cstate[i] = false;
	fun(i + 1);
}

signed main() {

	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	fun(0);
	cout << ans;


	return 0;
}