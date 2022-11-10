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

	void sssp(T src) {
		map<T, int> dist;
		queue<T> q;
		q.push(src);
		for (auto np : l) {
			T node = np.first;
			dist[node] = INT_MAX;
		}
		dist[src] = 0;

		while (!q.empty()) {
			T node = q.front();
			q.pop();
			for (auto nbr : l[node]) {
				if (dist[nbr] == INT_MAX) {
					q.push(nbr);
					dist[nbr] = dist[node] + 1;
				}
			}
		}
		for (auto i : dist) {
			cout << src << " - " << i.first << " : " << i.second << endl;
		}
		cout << endl;
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
	g.bfs(0);
	g.sssp(0);
	g.sssp(3);



	return 0;
}