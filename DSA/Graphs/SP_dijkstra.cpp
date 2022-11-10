#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	DIJKSTRA ALGORITHM
	SSSP for weighted graphs with no negetive weight cycle

	Steps :-

	1.Initialise dist[vertices] = INT_MAX, dist[src] = 0
	2.Maintain dist map dist[node] = dist from src
	3.Maintain a set storing { dist[node],node } (Sorted on the basis of distance)
	4.while set not empty
		get the node that has min dist in the set
		this node cannot be updated further

		go to its children and update there distances if reqd
		also make updates in the set and dist map is dist is reduced

	4. At the end dist map will contain min dist for each node from the src
*/

template<class T>
class Graph {

	unordered_map<T, list<pair<T, int>>> m;

public:

	void addEdge(T u, T v, int dist) {
		m[u].push_back({v, dist});
		m[v].push_back({u, dist});
	}
	void printAdj() {
		for (auto pair : m) {
			cout << pair.first << " -> ";
			for (auto p : pair.second) {
				cout << "(" << p.first << "," << p.second << ") ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void dijkstraSSSP(T src) {

		unordered_map<T, int> dist;
		// Set all distances to infinity
		for (auto j : m) {
			dist[j.first] = INT_MAX;
		}
		// Make a set to find out a node with minimum distance
		set<pair<int, T>> s;
		dist[src] = 0;
		s.insert({0, src});

		while (!s.empty()) {
			// Find the pair at the fron
			auto p = *s.begin();
			T node = p.second;
			int nodeDist = p.first;
			s.erase(s.begin());

			// Iterate over children of current node
			for (auto childPair : m[node]) {
				T child = childPair.first;
				int childWt = childPair.second;
				if (nodeDist + childWt < dist[child]) {
					// In the set updation is not possible
					// Therefore remove the old pair from set
					// and insert new pair in set
					auto f = s.find({dist[child], child});
					if (f != s.end()) {
						s.erase(f);
					}
					dist[child] = nodeDist + childWt;
					s.insert({dist[child], child});
				}
			}
		}

		// Print distances to all other nodes from src
		for (auto d : dist) {
			cout << src << " -> " << d.first << " = " << d.second << endl;
		}
	}


};




int main() {

	FIO;
	// Graph<int> g;
	// g.addEdge(1, 2, 1);
	// g.addEdge(1, 3, 4);
	// g.addEdge(2, 3, 1);
	// g.addEdge(3, 4, 2);
	// g.addEdge(1, 4, 7);
	// g.printAdj();
	// g.dijkstraSSSP(1);

	Graph<string> india;
	india.addEdge("Amritsar", "Delhi", 1);
	india.addEdge("Amritsar", "Jaipur", 4);
	india.addEdge("Jaipur", "Delhi", 2);
	india.addEdge("Jaipur", "Mumbai", 8);
	india.addEdge("Bhopal", "Agra", 2);
	india.addEdge("Mumbai", "Bhopal", 3);
	india.addEdge("Agra", "Delhi", 1);
	india.printAdj();
	india.dijkstraSSSP("Amritsar");

	return 0;
}