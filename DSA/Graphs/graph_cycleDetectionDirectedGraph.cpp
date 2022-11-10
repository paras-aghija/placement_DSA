#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	In a directed graph cycle is different from undirected graph
	We will use dfs to find cycle in a directed graph
	We will maintain a stack while performing dfs which will maintain the current path

	if we encounter a node that is visited then we will check if that node
	is present in the current path
	if present in current path the cycle is present else not

	we will implement stack as an array
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

	bool cycle_helper(int node, bool *visited, bool *stack) {
		visited[node] = true;
		// node becomes part of the current path
		stack[node] = true;

		for (int nbr : l[node]) {
			if (stack[nbr] == true) {
				return true;
			}
			if (visited[nbr] == false) {
				bool cycle_mila = cycle_helper(nbr, visited, stack);
				if (cycle_mila == true) {
					return true;
				}
			}
		}

		// leaving the node
		stack[node] = false;
		return false;
	}

	bool contains_cycle() {
		bool visited[V];
		bool stack[V];
		for (int i = 0; i < V; i++) {
			visited[i] = stack[i] = 0;
		}
		return cycle_helper(0, visited, stack);

	}
};


int main() {

	FIO;
	Graph g(7);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(1, 5);
	g.addEdge(5, 6);
	// g.addEdge(4, 2);

	cout << g.contains_cycle();

	return 0;
}