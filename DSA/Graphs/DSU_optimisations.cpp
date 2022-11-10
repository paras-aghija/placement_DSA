#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Optimisatiolns :-

		1.Path Compression (Find)
		2.Union by Rank (Union)

	PATH COMPRESSION

		In find function we would traverse untill parent[i] == -1
		which would lead to O(n) in worst case scenario
		During the traversal we can compress the path using path compression

		1 based indexing
		parent = [-1,1,2,2,3,3,5,6]

		find(7) -> Nodes encountered : 7 5 3 2 1
		We will make 1 as direct parent of all these nodes
		other nodes will be left as it is

		next time if we check find(7) -> O(1) time will be taken
		we will store the value being returned in parent[i]

	UNION BY RANK

		Store the rank of each node
		Rank : how many nodes are there in that particular set
		In union by rank smaller tree will be attached to a bigger tree
		for each node maintain a rank value n

	After these two optimisations overall complexity of both the operations
	is approximately O(1)

*/

class Graph {
	int V;
	list<pair<int, int>> l; // edge list

public:

	Graph(int n) {
		V = n;
	}

	void addEdge(int x, int y) {
		l.push_back({x, y});
	}

	// PATH COMPRESSION OPTIMISATION
	int findSet(int i, int  parent[]) {
		if (parent[i] == -1) {
			return i;
		}
		else {
			return parent[i] = findSet(parent[i], parent);
			// path compressed return + update
		}
	}

	// UNION BY RANK OPTIMISATION
	void unionSet(int x, int y, int parent[], int rank[]) {
		int a = findSet(x, parent);
		int b = findSet(y, parent);

		if (a != b) {
			if (rank[a] < rank[b]) {
				parent[a] = b;
				rank[b] += rank[a];
			}
			else {
				parent[b] = a;
				rank[a] += rank[b];
			}
		}
	}

	bool contains_cycle() {
		// DSU Logic to check if graph contains cycle or not
		// assuming all nodes of graph to be in their own set initially

		int parent[V];
		int rank[V];
		for (int i = 0; i < V; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}

		// iterate over the edge list
		for (auto edge : l) {
			int i = edge.first;
			int j = edge.second;

			int s1 = findSet(i, parent);
			int s2 = findSet(j, parent);

			if (s1 != s2) {
				unionSet(s1, s2, parent, rank);
			}
			else {
				return true;
			}
		}
		return false;
	}
};

int main() {

	FIO;
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);

	cout << g.contains_cycle();


	return 0;
}