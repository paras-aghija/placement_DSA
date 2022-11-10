#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	PRIM'S MINIMUM SPANNING TREE ALGORITHM (Greedy Algo)

	MST Set = [Nodes included in mst until certain time]
	Active Edge = edge from a vertex in mST set to V
	mST Edge = an edge that has been included in the MS so far

	Algorithm :-
	1. Start from any source vertex
	2. Start exploring all active edges and pick the one with the smallest weight
	3. Active edges will keep getting updated


*/

class Graph {
	// Adjacency list
	vector<pair<int, int>> *l;
	int V;

public:

	Graph(int n) {
		V = n;
		l = new vector<pair<int, int>>[n];
	}
	void addEdge(int x, int y, int w) {
		l[x].push_back({y, w});
		l[y].push_back({x, w});
	}

	int prim_mst() {
		// init a min priority queue
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

		// visited array whether node has been included in MST or not
		bool visited[V] = {0};
		int ans = 0;

		// begin
		Q.push({0, 0}); // weight, node
		while (!Q.empty()) {
			// pick out the edge with minimum weight
			auto best = Q.top();
			Q.pop();

			int to = best.second;
			int weight = best.first;

			if (visited[to]) {
				// discard the edge and continue
				continue;
			}

			ans += weight;
			visited[to] = 1;

			// add the new edges in the queue
			for (auto x : l[to]) {
				if (visited[x.first] == 0) {
					Q.push({x.second, x.first});
				}
			}
		}
		return ans;
	}
};

// Adj list notation -> (node, wt)
// queue notation -> (wt, node)
int main() {

	FIO;
	Graph g(4);
	g.addEdge(0, 1, 1);
	g.addEdge(1, 3, 3);
	g.addEdge(3, 2, 4);
	g.addEdge(2, 0, 2);
	g.addEdge(0, 3, 2);
	g.addEdge(1, 2, 2);

	cout << g.prim_mst() << endl;


	return 0;
}