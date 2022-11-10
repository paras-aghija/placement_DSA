#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Bipartite Graph :-

	- You can divide all vertices of graph in 2 sets
	- such that all edges of the graph are from set1 to set2

	Example 1 :-
	2----1----3
	|____4____|

	S1 = {1,4}
	S2 = {2,3}
	We can assign colors to each node (choosing from 2 colors)
	Division into 2 sets is possible therefore given graph is a bipartite graph

	Example 2 :-
		1
	   / \
	  2  3
	 /\  \
	4 5  6

	Give one color to each level then we can divie vertices into 2 sets
	Therefore this graph is also bipartite
	Say odd levels belong to set1 and even levels belong to set2

	Example 3 :-
	Colors
	1   2   1   2  1
	1---2---3---4--5
	|______________|

	colors of 5 and 1 are same therefore property is violated
	Therefore not a bipartite graph

	* If a graph contains a cycle and cycle have odd number of nodes
	  then graph is not a bipartite graph
*/

bool dfs_helper(vector<int> graph[], int node, int *visited, int color, int parent) {
	visited[node] = color;
	for (auto nbr : graph[node]) {
		// if nbr is not visited
		if (visited[nbr] == 0) {
			bool isBipartite = dfs_helper(graph, nbr, visited, 3 - color, node);
			if (isBipartite == false) {
				return false;
			}
		}

		// if nbr is visited and it is parent
		else if (nbr != parent and visited[nbr] == color) {
			return false;
		}
	}
	return true;
}

bool dfs(vector<int> graph[], int N) {
	int visited[N] = {0};
	// 0 - not visited, 1 - color 1, 2 - color 2
	int color = 1;
	bool ans = dfs_helper(graph, 0, visited, color, -1);

	// colors
	for (int i = 0; i < N; i++) {
		cout << i << " color : " << visited[i] << endl;
	}
	return ans;

}

int main() {

	FIO;
	int N, M;
	cin >> N >> M;

	vector<int> graph[N];
	while (M--) {
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	// BFS or DFS, by coloring the nodes at each step
	// if current node has color one then neighbouring node will have color 2
	// if we find a visited nbr with same color as current node, not bipartite
	dfs(graph, N) == 1 ? cout << "Bipartite" : cout << "Not Bipartite";


	return 0;
}