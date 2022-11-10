#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

Given n ropes of different sizes, we have to join the ropes
Cost of joining 2 ropes of different sizes A, B = (A+B)
find min cost to join all the ropes

*/

int main() {

	FIO;
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		pq.push(t);
	}
	int ans = 0;
	while (pq.size() != 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	cout << ans << endl;

	return 0;
}