#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, pair<int, int>> node;

int main() {

	FIO;
	// rows and columns are sorted
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> v(n, vector<int> (m));
	vector<vector<bool>> vis(n, vector<bool> (m, 0));

	priority_queue<node, vector<node>, greater<node>> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	pq.push({v[0][0], {0, 0}});
	vis[0][0] = 1;
	int val;
	while (k--) {
		node curr = pq.top();
		pq.pop();
		val = curr.first;
		int x = curr.second.first;
		int y = curr.second.second;
		// cout << val << endl;
		if (!vis[x + 1][y]) {
			pq.push({v[x + 1][y], {(x + 1), y}});
			vis[x + 1][y] = 1;
		}
		if (!vis[x][y + 1]) {
			pq.push({v[x][y + 1], {x, (y + 1)}});
			vis[x][y + 1] = 1;
		}
	}
	cout << val << endl;


	return 0;
}

/*
Input

4 4 7
10 20 30 40
15 25 35 45
24 29 27 48
32 33 39 40

*/