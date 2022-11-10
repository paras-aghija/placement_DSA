#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	DISJOINT SET UNION

	DSU Provides 2 operations :-
		1.Find
		2.Union

	Disjoint Set :-

		S1 = {1,2,3,4}
		S2 = {5,6,7}
		S3 = {8,9}

		find(8) => S3
		find(6) => S2

		union(S2,S3);
		unoin(6,8); merge sets containing element 6 and element 8

	We ave to implement these two functionalities with minimum complexities

	Basic -> O(n)
	Optimisation -> O(1)
		Path Compression
		Union by Rank
*/

/*
	DSU Data Structure Visualisation

	parent = [-1,-1,-1,-1]

	Let there be 4 sets

	1	2	3	4

	union(1,2);
	initially 1 belongs to its own set and 2 belongs to its own set
	parent is -1 therefore that node itself is a set
	we will now unite these two sets and parent of combined set will be 1
	parent = [-1,1,-1,-1]
	1 is parent of 2

	union(3,4);
	parent = [-1,1,-1,3]

	From the parent array we can get the number of sets and set leaders

	union(1,4);
	s1 = find leader of 1 => 1
	s2 = find leader of 4 => 3
	combine the two sets now if (s1!=s2)
	leader of 3 is now 1
	parent = [-1,1,1,3]

	union(2,3)
	s1 = find(2) = 1;
	s2 = find(3) = 1;
	since s1 == s2 therefore if 2 and 3 are being connected
	then cycle will be present in the graph

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

	// O(n) worst case complexity
	int findSet(int i, int  parent[]) {
		if (parent[i] == -1) {
			return i;
		}
		else {
			return findSet(parent[i], parent);
		}
	}

	void unionSet(int x, int y, int parent[]) {
		int a = findSet(x, parent);
		int b = findSet(y, parent);

		if (a != b) {
			parent[b] = a;
		}
	}

	bool contains_cycle() {
		// DSU Logic to check if graph contains cycle or not
		// assuming all nodes of graph to be in their own set initially

		int parent[V];
		for (int i = 0; i < V; i++) {
			parent[i] = -1;
		}

		// iterate over the edge list
		for (auto edge : l) {
			int i = edge.first;
			int j = edge.second;

			int s1 = findSet(i, parent);
			int s2 = findSet(j, parent);

			if (s1 != s2) {
				unionSet(s1, s2, parent);
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