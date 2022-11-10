#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	SPANNING TREE :-
	Given a weighted undirected graph
	Spanning Tree : Tree that connects all vertices of a graph without cycle
	Tree -> No cycle present
	To join V vertices V-1 edges will be required
	Spanning Tree is a subset of edges
	Graph forms a single connected component

	Cost of a spanning tree : Total weight of all edges in spanning tree

	MINIMUM SPANNING TREE : Spanning tree with minimum cost

*/

/*
	KRUSKAL'S ALGORITHM (Greedy Algorithm)

	Greedy Algo : By choosing a local minima at each step we reach global minima

	Graph :
	1 2 1
	1 3 2
	1 4 2
	2 3 2
	2 4 3
	3 4 3

	1. Sort all edges based upon weight
	2. Go to sorted list and start picking edges
	3. If vertices of selected edge belong to different sets then it can be used
	4. This can be checked by using DSU data structure

	1 2 1
	1 3 2
	1 4 2

	MST weight = 5

*/


// DSU data structure
// Path compression and union by rank optimisation
class DSU {
	int *parent;
	int *rank;

public:

	DSU(int n) {
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;  // each node is a set in itself
		}
	}

	// find function
	int find(int i) {
		if (parent[i] == -1) {
			return i;
		}

		return parent[i] = find(parent[i]);
	}


	// union function
	void unite(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);
		if (s1 != s2) {
			// union by rank
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};

// edgelist graph
class Graph {
	vector<vector<int>> edgeList;
	int V;

public:

	Graph(int V) {
		this->V = V;
	}

	void addEdge(int x, int y, int w) {
		edgeList.push_back({w, x, y});
	}

	int kruskal_mst() {
		// Main logic
		// 1. Sort all the edges based upon the wieght
		sort(edgeList.begin(), edgeList.end());

		// Initialise a DSU
		DSU s(V);

		int ans = 0;
		for (auto edge  : edgeList) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			// take edge in mst if they belong to different sets
			if (s.find(x) != s.find(y)) {
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}

};
int main() {

	FIO;

	// Graph g(4);
	// g.addEdge(0, 1, 1);
	// g.addEdge(1, 3, 3);
	// g.addEdge(3, 2, 4);
	// g.addEdge(2, 0, 2);
	// g.addEdge(0, 3, 2);
	// g.addEdge(1, 2, 2);

	int n, m;
	cin >> n >> m;

	Graph g(n);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g.addEdge(x - 1, y - 1, w);
	}

	cout << g.kruskal_mst() << endl;


	return 0;
}