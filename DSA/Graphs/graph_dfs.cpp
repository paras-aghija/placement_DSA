#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
template<typename T>
class Graph {
	// not weighted
	map<T, list<T>> l;

public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(T src) {
		map<T, bool> visited;
		queue<T> q;
		q.push(src);
		visited[src] = true;
		while (!q.empty()) {
			T node = q.front();
			q.pop();
			cout << node << " ";
			for (auto nbr : l[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
		cout << endl;
	}

	void dfs_helper(T src, map<T, bool> &visited) {
		cout << src << " - ";
		visited[src] = true;
		for (auto nbr : l[src]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited);
			}
		}
	}

	void dfs(T src) {
		map<T, bool> visited;
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}
		dfs_helper(src, visited);
		cout << endl;
	}

	void dfs_cc() {
		map<T, bool> visited;
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}
		int cnt = 0;
		for (auto p : l) {
			T node = p.first;
			if (!visited[node]) {
				cout << "Component" << ++cnt << endl;
				dfs_helper(node, visited);
				cout << endl;
			}
		}
	}
};

int main() {

	FIO;
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	g.addEdge(6, 7);
	g.addEdge(7, 8);
	g.bfs(0);
	g.dfs(0);
	g.dfs_cc();



	return 0;
}