#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF 10000
using namespace std;

/*
	Floyd Warshal Shortest Path Algorithm
	It is an all pair shortest path algorithm
	gives shortest path for each pair of nodes

	- DP Based Algorithm
	- Time complexity O(N^3) N is the number of vertices
	- Space Complexity O(N^2)
	- Works with negetive edges

	Example :-

	Graph : [(1,3,-2), (2,1,4), (2,3,3), (3,4,2), (4,2,-1)]

	Step 0 : Initial weights in 2d graph format

	   1   2   3   4
	1[ 0 |inf|-2 |inf]
	2[ 4 | 0 | 3 |inf]
	3[inf|inf| 0 | 2 ]
	4[inf|-1 |inf| 0 ]

	Step 2 : Update matrices in phases

	Phase 1:Try to update shortest paths with 1 as intermediate vertices
		   Leave the 1st row and 1st column and  diagonal elements


		   Can you go via 1
			1. 2 -> 3 YES Updates to 4-2 = 2 > 3(initial dist)

			d[i][j] = min {
				1.d[i][j]
				2.d[i][k] + d[k][j]
			}

			2. 2 -> 4 NO 2->1 = 4 but 1->4=inf currently No Update

			3. 3 -> 2 No Update

			4. 3 -> 4 No Update

	   1   2   3   4
	1[ 0 |inf|-2 |inf]
	2[ 4 | 0 | 2 |inf]
	3[inf|inf| 0 | 2 ]
	4[inf|-1 |inf| 0 ] final updated matrix for Phase 1

	Phase 2:Take 2 as intermediate vertex
			Leave row 2 and col 2 and diagonals

			1. 4->1 : 4->2 then 2->1 = 3 Updated
			2. 4->3 : 4->2 then 2->3 = 1 Updated

	   1   2   3   4
	1[ 0 |inf|-2 |inf]
	2[ 4 | 0 | 2 |inf]
	3[inf|inf| 0 | 2 ]
	4[ 3 |-1 | 1 | 0 ] final updated matrix for Phase 2

	Phase 3: Take 3 as intermediate vertex

	   1   2   3   4
	1[ 0 |inf|-2 | 0 ]
	2[ 4 | 0 | 2 | 4 ]
	3[inf|inf| 0 | 2 ]
	4[ 3 |-1 | 1 | 0 ] final updated matrix for Phase 3

	Phase 4: Take 4 as intermediate vertex

	   1   2   3   4
	1[ 0 |-1 |-2 | 0 ]
	2[ 4 | 0 | 2 | 4 ]
	3[ 5 | 1 | 0 | 2 ]
	4[ 3 |-1 | 1 | 0 ] final updated matrix for Phase 4

	From the final matrix we can tell SP between all the vertices
*/

vector<vector<int>> floyd_warshall(vector<vector<int>> graph ) {
	vector<vector<int>> dist(graph);
	int V = graph.size();
	// Phases, in kth phase we include 1,2,...k as intermediate vertices
	for (int k = 0; k < V; k++) {
		// Make Updates in matrix
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				// if vertex k is included and
				// can we minimise the by taking k as intermediate vertex
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	// cycle check
	// If distance of any verex from itself
	// becomes negative, then there is a negative
	// weight cycle.
	for (int i = 0; i < V; i++) {
		if (dist[i][i] < 0) {
			cout << "Negetive Cycle Detected";
			exit(0);
		}
	}
	return dist;
}

int main() {

	FIO;
	// 4 vertices
	vector<vector<int>> graph = {
		{0, INF, -2, INF},
		{4, 0, 3, INF},
		{INF, INF, 0, 2},
		{INF, -1, INF, 0}
	};

	vector<vector<int>> dist = floyd_warshall(graph);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// cout << i << " -> " << j << " : " << dist[i][j] << endl;
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}