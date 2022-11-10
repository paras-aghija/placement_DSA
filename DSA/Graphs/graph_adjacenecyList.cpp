#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

class Graph {
	int V;
	list<int> *l;
public:
	Graph(int V) {
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
		// Undirected edge
	}

	void printAdjList() {
		for (int i = 0; i < V; i++) {
			cout << i << " : ";
			for (auto nbr : l[i]) {
				cout << nbr << " ";
			}
			cout << endl;
		}
	}
};

int main() {

	FIO;
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 2);
	g.printAdjList();

	return 0;
}