#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Unlike previous method we will start from bottom
	Start from the first non leaf node => n/2

	Time Complexity

	2h-1*0 + 2h-2*1 + 2h-3*2 .... 1*h = S
	S = 2^h-1 [ 1/2 + 2/2^2 + 3/2^3 ... ] AGP
	S = 2^h-1 [...] ~ O(2^h)
	h ~ logN
	Time Complexity O(N)

	Intuitve Explanation why tc is less

	For approach 1:  top down
	Amount of work done at last level is h
	Amount of work done at root is 1

	For approach 2: bottom up
	Amount of work done at last level is 1
	Amount of work done at root is h

	Therefore in approach higher amount of work is
	being done on more nodes

*/

void heapify(vector<int> &v, int i) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int mini = i;
	if (l < v.size() and v[l] < v[mini]) {
		mini = l;
	}
	if (r < v.size() and v[r] < v[mini]) {
		mini = r;
	}
	if (mini != i) {
		swap(v[i], v[mini]);
		heapify(v, mini);
	}
}

void printv(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {

	FIO;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {cin >> v[i];}

	for (int i = (n - 1) / 2; i >= 0; i--) {
		heapify(v, i);
	}
	printv(v);
	return 0;
}