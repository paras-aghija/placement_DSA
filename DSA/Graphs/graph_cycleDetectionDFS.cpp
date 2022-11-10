#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Given a undirected graph find if graph contains a cycle or not
	Approach :-
	Graph contains a cycle if there is more than one way to visit a node
	parent should be taken care of **
*/


class Graph {
	int V;
	list<int> *l;

public:

	Graph(int x) {
		V = x;
		l = new list<int>[V];
	}

	void addEdge(int x, int y, bool directed = true) {
		l[x].push_back(y);
		if (!directed) {
			l[y].push_back(false);
		}
	}

	bool cycle_helper(int node, bool *visited, int parent) {
		visited[node] = true;
		for (auto nbr : l[node]) {
			// two cases
			if (!visited[nbr]) {
				// go and recursively visit the nbr
				bool cycle_mila = cycle_helper(nbr, visited, node);
				if (cycle_mila == true) {
					return true;
				}
			}
			else if (nbr != parent) {
				return true;
			}
		}
		return false;
	}

	bool contains_cycle() {
		bool visited[V];
		for (int i = 0; i < V; i++) {
			visited[i] = false;
		}
		return cycle_helper(0, visited, -1);
	}
};



int main() {

	FIO;

	Graph g(5);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 0);

	cout << g.contains_cycle();



	return 0;
}