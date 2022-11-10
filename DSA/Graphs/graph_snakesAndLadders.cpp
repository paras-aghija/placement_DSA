#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

template<typename T>
class Graph {
	// not weighted
	map<T, list<T>> l;

public:
	void addEdge(T x, T y) {
		// cout << "adding edge " << x << " " << y << endl;
		l[x].push_back(y);
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

	void sssp(T src, T dest) {
		map<T, int> dist;
		queue<T> q;
		map<T, T> parent;
		q.push(src);
		for (auto np : l) {
			T node = np.first;
			dist[node] = INT_MAX;
		}
		dist[src] = 0;
		parent[src] = src;

		while (!q.empty()) {
			T node = q.front();
			q.pop();
			for (auto nbr : l[node]) {
				if (dist[nbr] == INT_MAX) {
					q.push(nbr);
					dist[nbr] = dist[node] + 1;
					parent[nbr] = node;
				}
			}
		}

		for (auto i : dist) {
			cout << src << " - " << i.first << " : " << i.second << endl;
		}
		cout << endl;
		int d = dist[dest];
		cout << src << " - " << dest << " : " << d;
		cout << endl;

		T temp = dest;
		while (temp != src) {
			cout << temp << "<--";
			temp = parent[temp];
		}
		cout << src << endl;
	}
};

int main() {

	FIO;
	int board[50] = {};

	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;

	// add all edges to graph
	Graph<int> g;
	for (int i = 0; i <= 36; i++) {
		for (int dice = 1; dice <= 6; dice++) {
			int j = i + dice;
			j += board[j];
			if (j <= 36) {
				g.addEdge(i, j);
			}
		}
	}
	// graph does not know that a node 36 exist
	g.addEdge(36, 36);

	g.sssp(0, 36);



	return 0;
}