#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define w first
#define p second
using namespace std;

vector<pair<int, int>> v(100);
int fun(int n, int cap) {
	if (n == -1 or cap == 0) return 0;

	// dont take nth item
	int ans = fun(n - 1, cap);

	// take the nth item
	if (v[n].w <= cap) {
		ans = max(ans, v[n].p + fun(n - 1, cap - v[n].w));
	}
	return ans;
}

int main() {

	FIO;
	int n, W;
	cin >> n >> W;
	for (int i = 0; i < n; i++) {
		cin >> v[i].w >> v[i].p;
	}
	cout << fun(n - 1, W);

	return 0;
}