#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

/*

	Problem link : https://www.spoj.com/problems/BALIFE/

*/


int main() {

	FIO;
	int n;
	while (1) {
		cin >> n;
		if (n == -1) {
			break;
		}
		vector<int> v(n);
		int max_load = 0, load = 0;
		for (int &x : v) {
			cin >> x;
			load += x;
		}

		if (load % n != 0) {
			cout << -1 << endl;
			continue;
		}

		load = load / n;
		int diff = 0;
		for (int i = 0; i < n; i++) {
			diff += (v[i] - load);
			max_load = max(max_load, abs(diff));
		}
		cout << max_load << endl;
	}

	return 0;
}