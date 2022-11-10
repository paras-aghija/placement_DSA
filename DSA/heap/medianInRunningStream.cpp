#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	Brute force: O(n2logn)
	Sorted insert: O(n2)
	Heap : O(nlogn)

	leftHeap => data elements less than median
	rightHeap => data elements greater than median
*/

int main() {

	FIO;
	priority_queue<int> leftHeap;
	priority_queue<int, vector<int>, greater<int>> rightHeap;
	int d;
	cin >> d;
	// mih.push(d);
	float med = d;
	// cout<<"Median : "<<med<<endl;
	while (d != -1) {
		if (leftHeap.size() > rightHeap.size()) {
			if (d < med) {
				rightHeap.push(leftHeap.top());
				leftHeap.pop();
				leftHeap.push(d);
			}
			else {
				rightHeap.push(d);
			}
			med = (float)(leftHeap.top() + rightHeap.top()) / 2.0;
		}
		else if (leftHeap.size() == rightHeap.size()) {
			if (d < med) {
				leftHeap.push(d);
				med = leftHeap.top();
			}
			else {
				rightHeap.push(d);
				med = rightHeap.top();
			}
		}
		else {
			if (d < med) {
				leftHeap.push(d);
			}
			else {
				leftHeap.push(rightHeap.top());
				rightHeap.pop();
				rightHeap.push(d);
			}
			med = (float)(leftHeap.top() + rightHeap.top()) / 2.0;
		}

		cout << "Medain : " << med << endl;
		cin >> d;
	}

	return 0;
}

/*
Input
1
1
5
4
3
0
0
8
-1
*/