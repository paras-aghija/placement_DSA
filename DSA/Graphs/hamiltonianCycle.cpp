#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Hamiltonian cycle: cyclic path starting and ending
	at a node ansd visiting all other nodes exactly once
*/

vector<int> curPath;
int n, m, src;
map < int, vector<int>> g;
vector<bool> vis(5, 0);

template<class T>
void printv(vector<T> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

void hamiltonian(int src) {
	vis[src] = true;
	curPath.push_back(src);

	if (curPath.size() == n) {
		// process the path
		printv(curPath);
		vis[src] = false;
		curPath.pop_back();

		return;
	}

	for (int child : g[src]) {
		// cout << src << " " << child << endl;
		if (!vis[child]) {
			hamiltonian(child);
		}
	}
	vis[src] = false;
	curPath.pop_back();
}

int main() {

	FIO;
	cin >> n >> m >> src;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	hamiltonian(src);

	return 0;
}