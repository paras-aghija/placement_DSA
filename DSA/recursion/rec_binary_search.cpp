#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int bs(vector<int> &a, int x, int y, int val) {
	if (x == y) { return (a[x] == val) ? x : -1; }
	int mid = (x + y) / 2;
	if (a[mid] == val) { return mid; }
	else if (a[mid] < val) { return bs(a, mid + 1, y, val); }
	else { return bs(a, x, mid - 1, val); }

}

int main() {

	FIO;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int x;
	cin >> x;
	cout << bs(a, 0, n - 1, x);
	return 0;
}