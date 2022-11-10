#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Brute force: NKlog(NK)
	Heap : NK(log(K))

*/

typedef pair<int, pair<int, int>> node;
// value, array_index, element_index

vector<int> mergeKsorted(vector<vector<int>> v) {
	vector<int> result;
	priority_queue<node, vector<node>, greater<node>> pq; //min pq
	// insert 0th element of each array in pq
	for (int i = 0; i < v.size(); i++) {
		pq.push({v[i][0], {i, 0}});
	}
	while (!pq.empty()) {
		node t = pq.top();
		pq.pop();
		int val = t.first;
		int ai = t.second.first;
		int ei = t.second.second;
		if (ei + 1 < v[ai].size()) {
			pq.push({v[ai][ei + 1], {ai, ei + 1}});
		}
		result.push_back(val);
	}
	return result;
}


int main() {

	FIO;
	vector<vector<int>> v = {
		{2, 6, 12, 15},
		{1, 3, 14, 20},
		{3, 5, 8, 10}
	};
	vector<int> res = mergeKsorted(v);
	for (int x : res) {
		cout << x << " ";
	}

	return 0;
}