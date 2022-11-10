#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


/*
	KOSARAJU'S ALGORITHM

	Directed Graph :-

	Graph g

	1->0
	0->2
	2->1
	0->3
	3->5
	5->6
	6->3
	3->4

	Strongly connexted component : Subset/Component of graph in which all nodes can
								   be accessed through every other node

	SCC 1 : 0,1,2
	SCC 2 : 3,5,6
	SCC 3 : 4

	Kosaraju's Algorithm is used to find SCC's in a directed Graph

	Steps :-

	1.Do a DFS on the entire graph and get andordering based upon finish time

		Say we start DFS call from 3
		vector v;
		when returning from node push node into vector
		v : [6.5.4.3]
		Some nodes are still left
		final v : [6,5,4,3,1,2,0]
		Using a vector as a stack

	2. Reverse the original graph

		Graph r

		1<-0
		0<-2
		2<-1
		0<-3
		3<-5
		5<-6
		6<-3
		3<-4

	3.Pick vertices from the ordering and start doing DFS on the reversed graph

		Vector c;
		push into the vector while returning
		DFS(0);
		c : [2,1,0] (SCC 1)

		in ordereing traverse leftwards

		DFS(3);
		c : [6,5,3] (SCC 2)

		DFS(4);
		c : [4] (SCC 3)
*/

void dfs(vector<int> graph[], int i, bool *visited, vector<int> &stack) {
	visited[i] = true;
	for (auto nbr : graph[i]) {
		if (!visited[nbr]) {
			dfs(graph, nbr, visited, stack);
		}
	}
	stack.push_back(i);
}

void dfs2(vector<int> graph[], int i, bool *visited) {
	visited[i] = true;
	cout << i << " ";
	for (auto nbr : graph[i]) {
		if (!visited[nbr]) {
			dfs2(graph, nbr, visited);
		}
	}

}


void solve(vector<int> graph[], vector<int> rev_graph[], int N) {
	bool visited[N];
	memset(visited, 0, N);
	vector<int> stack;

	// 1.Store vertices in stack acc to dfs finish time
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs(graph, i, visited, stack);
		}
	}

	// ordering  : stack
	// 2. reverse DONE

	// 3. Do DFS acccording to ordering in the stack over reversed graph
	memset(visited, 0, N);
	char component_name = 'A';
	for (int x = stack.size() - 1; x >= 0; x--) {
		int node = stack[x];
		if (!visited[node]) {
			// theres a component starting from this node
			cout << "Component " << component_name++ << " : ";
			dfs2(rev_graph, node, visited);
			cout << endl;
		}
	}
}

int main() {

	FIO;
	int N;
	cin >> N;
	vector<int> graph[N];
	vector<int> rev_graph[N];

	int m;
	cin >> m;

	while (m--) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		rev_graph[y].push_back(x);
	}
	solve(graph, rev_graph, N);


	return 0;
}

/*
	INPUT
	7 8
	2 1
	1 0
	0 2
	0 3
	3 5
	5 6
	6 3
	3 4
*/