#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
// some bug in this code....


int fact(int n) {
	return (n <= 1) ?  1 :  n * fact(n - 1);
}


template<typename T>
class Graph {
	// not weighted
	int V;
	map<T, list<T>> l;

public:

	Graph(int n) {
		V = n;
	}
	void addEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	int dfs(T src, map<T, bool> &visited) {
		visited[src] = true;
		// cout << src << endl;
		int ans = 1;
		for (auto nbr : l[src]) {
			if (!visited[nbr]) {
				ans += dfs(nbr, visited);
			}
		}
		return ans;
	}

	void solve() {
		map<T, bool> visited;
		for (int i = 0; i <= V; i++) {
			visited[i] = false;
		}
		int ans = fact(V) / (fact(V - 2) * 2);
		for (auto p : l) {
			T node = p.first;
			int local = 0;
			if (!visited[node]) {
				local = dfs(node, visited);
				ans -= fact(local) / (fact(local - 2) * 2);
			}
		}
		cout << ans << endl;
	}

};

int main() {

	FIO;
	int n, q;
	cin >> n >> q;
	Graph<int> g(n);
	int a, b;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		g.addEdge(a, b);
	}
	g.solve();


	return 0;
}