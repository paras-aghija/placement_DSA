#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Shortest cycle in an undirected graph
	perform a bfs if you encounter a node to a visited node
	then that will be a backedge which will be forming the cycle

	we will have to find all the cycles int a graph
	we will have to apply bfs to every other node
	bcz each other node might be contained in a cycle
*/
const int N = 100005, M = 22;
vector<int> graph[N];

void bfs(int src, int n, int &ans) {
	vector<int> dist(n + 1, INT_MAX);
	queue<int> Q;

	Q.push(src);
	dist[src] = 0;
	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();
		for (auto nbr : graph[curr]) {
			if (dist[nbr] == INT_MAX) {
				// neighbour is not visited
				dist[nbr] = dist[curr] + 1;
				Q.push(nbr);
			}
			else {
				// nbr is already visited
				// check if nbr is not parent
				if (dist[nbr] >= dist[curr]) {
					// this edge is not parent
					// backedge encountered
					ans = min(ans, dist[nbr] + dist[curr] + 1);
				}
			}
		}
	}
}

void solve() {
	int n, m, ans;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	ans = n + 1; //not possible
	for (int i = 1; i <= n; i++) {
		bfs(i, n, ans);
	}
	if (ans == n + 1) {
		cout << "No cycle";
	}
	else {
		cout << "Shortest cycle is of length : " << ans;
	}
}

int main() {

	FIO;
	solve();

	return 0;
}