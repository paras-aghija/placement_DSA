#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	priority_queue is a data structure
	which stores data in the priority queue
	on basis of priority

	max- priority_queue => return max element on pop
	min- priority_queue => return min elmeent on pop

	Complexities:

	Insertion: O(logn)
	Deletion: O(logn)
	Top: O(1)	returns priority element

	Priority queue uses heap as underlying data structure
	push: O(logn)
	pop: O(logn)
	top: O(1)

*/

int main() {

	FIO;
	// max priority queue
	// priority_queue<int> pq;
	// min priority queue
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		pq.push(t);
	}

	// remove the elements
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}