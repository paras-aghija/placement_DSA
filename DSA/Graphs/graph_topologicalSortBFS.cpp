#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	TOPOLOGICAL SORTING USING BFS :-

	Terminologies :-

		Indegree : Incoming Edges
		Outdegree : Outgoing Edges

	Find nodes with 0 indegree and push them into a queue
	as these nodes do not depend on any other node
	Pop nodes from queue and now indegree of its children reduces by 1
	as we encounter a node with indegree 0 we push it into the queue
	and we perform operatins until queue is not empty


*/

class Graph {
	list<int> *l;
	int V;
public:
	Graph(int n) {
		this->V = n;
		l = new list<int> [n];
	}
	void addEdge(int x, int y) {
		l[x].push_back(y);
	}

	void topological_sort() {
		vector<int> indegree(V, 0);
		for (int i = 0; i < V; i++) {
			int x = i;
			for (auto y : l[i]) {
				indegree[y]++;
			}
		}

		// bfs
		// 1. find nodes with 0 indegree
		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int node = q.front();
			cout << node << " ";
			q.pop();
			for (auto nbr : l[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}
};


int main() {

	FIO;
	Graph g(6);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(4, 5);
	g.addEdge(2, 5);

	g.topological_sort();

	return 0;
}