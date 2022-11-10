#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
using namespace std;

/*

	There are a total of 5 popular Shortest Path Algorithms
	Out of these 3 are SSSP's

	1. BFS SSSP
	2. Dijkstra
	3. Bellman Ford

	4.Floyd Warshall (APSP)
	4.Johnson's Algo (APSP)

	BFS => Case was all edges were unweighted 				O(V+E)
	Dijkstra => Weighted Graph + Positive Edges 			O(Elog(V))
	Bellman Ford => Weighted + Directed + Negetive Edges 	O(VE)

	Steps :-

	1. Initialise dist[vertices] = INT_MAX, dist[src] = 0
	2. Relax all edges V-1 times [MOST IMPORTANT, NOT INTUTIVE]
	3. Do graph contains negetive weight cycle

	What is relaxation of an edge :-

		  wt
	u ---------> v
   	dist[u]		 dist[v]

   	if(dist[v] > dist[u] + wt){
		dist[v] = dist[u] + wt;
   	}

   	## Checking for negetive wt cycle

   	If graph contains a negetive wt cycle
   	suppose there is a cycle with total cyclic wt = -1;
   	then every incoming path in that cycle can be reduced by 1
   	towards a any dest node outside the cycle for each cyclic traversal
   	therefore shortest path for such graphs cannot be generated

   	How to check if negetive cycle present or not ?
   	for vth relaxation if distances change then negetive cycle is present
*/

vector<int> bellman_ford(int V, int src, vector<vector<int>> edges) {
	// distance vector
	vector<int> dist(V + 1, INT_MAX);
	dist[src] = 0;
	// relax all edges V-1 times
	for (int i = 0; i < V - 1; i++) {
		for (auto edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
	}
	// check for negetive wt cycle
	for (auto edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];
		if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
			cout << "Negetive Weight Cycle found" << endl;
			exit(0);
		}
	}
	return dist;


}


int main() {

	FIO;
	int n, m; // vertices, edges
	cin >> n >> m;
	// Edge list representation
	vector<vector<int>> edges; // (a,b,2) (c,d,4)
	int u, v, wt;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> wt;
		edges.pb({u, v, wt});
	}
	// bellman ford algorithm
	vector<int> dist = bellman_ford(n, 1, edges);
	for (int i = 1; i <= n; i++) {
		cout << 1 << " -> " << i << " = " << dist[i] << endl;
	}
	return 0;
}