#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define deb(x) cout<<#x<<": "<<x<<endl;
#define pb push_back
using namespace std;

/*

	Problem link: https://www.spoj.com/problems/DEFKIN/

*/

void printv(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> rows(k), cols(k);

	if (k == 0) {
		cout << n*m << endl;
		return;
	}

	for (int i = 0; i < k; i++) {
		cin >> rows[i] >> cols[i];
	}

	sort(rows.begin(), rows.end());
	sort(cols.begin(), cols.end());

	int dx = rows[0] - 1;
	int dy = cols[0] - 1;


	for (int i = 1; i < k; i++) {
		dx = max(dx, rows[i] - rows[i - 1] - 1);
		dy = max(dy, cols[i] - cols[i - 1] - 1);
	}

	dx = max(n - rows[k - 1], dx);
	dy = max(m - cols[k - 1], dy);

	cout << dx*dy << endl;

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