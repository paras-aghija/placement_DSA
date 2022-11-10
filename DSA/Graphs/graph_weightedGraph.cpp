#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

class Graph {
	unordered_map<string, list<pair<string, int>>> l;
public:
	void addEdge(string x, string y, bool bidir, int wt) {
		l[x].push_back(make_pair(y, wt));
		if (bidir) {
			l[y].push_back(make_pair(x, wt));
		}
	}
	void printAdj() {
		for (auto e : l) {
			cout << e.first << " -> ";
			for (auto nbr : e.second) {
				cout << "(" << nbr.first << "," << nbr.second << ") ";
			}
			cout << endl;
		}
	}
};

int main() {

	FIO;
	Graph g;
	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D", true, 40);
	g.addEdge("A", "C", true, 10);
	g.addEdge("C", "D", true, 40);
	g.addEdge("A", "D", false, 50);
	g.printAdj();


	return 0;
}