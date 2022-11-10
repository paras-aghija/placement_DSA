#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	TOPOLOGICAL SORT :-

	Givn a directed dependecy graph :-

	Python -> Data Preprocessing
	Python -> Pytorch
	Data Preprocessing -> ML Baiscs
	Python -> ML Basics
	Pytorch -> Deep Learning
	ML Basics -> Deep Learning
	Deep Learning -> Face Recognitin AI
	Data Set -> Face Recognition AI

	Topological Sort is a Linear ordering

	Python -> Data Preprocessing -> ML Basics Pytorch -> D.L  Dataset -> Face AI
	|___________________________________|_______|		 | |				|
										|_______________ | |________________|

	This can only be done in directed acyclic graph
	Topological Sorting using DFS
*/
template<typename T>
class Graph {
	// not weighted
	map<T, list<T>> l;

public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
		// l[y].push_back(x);
	}

	void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering) {
		visited[src] = true;

		for (auto nbr : l[src]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited, ordering);
			}
		}

		// before returning
		ordering.push_front(src);
		return;
	}

	void dfs() {
		map<T, bool> visited;
		list<T> ordering;
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}
		for (auto p : l) {
			T node = p.first;
			if (!visited[node]) {
				dfs_helper(node, visited, ordering);
			}
		}

		for (auto node : ordering) {
			cout << node << endl;
		}
	}

};
int main() {

	FIO;
	Graph<string> g;
	g.addEdge("Python", "DataPreprocessing");
	g.addEdge("Python", "PyTorch");
	g.addEdge("Python", "ML");
	g.addEdge("DataPreprocessing", "ML");
	g.addEdge("PyTorch", "DL");
	g.addEdge("ML", "DL");
	g.addEdge("DL", "FaceRecognition");
	g.addEdge("Dataset", "FaceRecognition");

	g.dfs();


	return 0;
}