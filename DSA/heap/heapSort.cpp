#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	Inplace sorting algorithm

	-Convert array into a maxHeap
	-shrink the heap similar to pop
	-do not delete the last element from the vector in algo of pop operation



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

void heapify2(vector<int> &v, int i, int n) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int mini = i;
	if (l < n and v[l] < v[mini]) {
		mini = l;
	}
	if (r < n and v[r] < v[mini]) {
		mini = r;
	}
	if (mini != i) {
		swap(v[i], v[mini]);
		heapify2(v, mini, n);
	}
}

void heapSort(vector<int> &v) {
	int n = v.size();
	// build max heap
	for (int i = (n - 1) / 2; i >= 0; i--) {
		heapify(v, i);
	}

	while (n > 1) {
		swap(v[0], v[n - 1]);
		// remove that element from the heap
		n--;
		// actual size of the vector remains same
		heapify2(v, 0, n);
	}
}

int main() {

	FIO;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &x : v) {cin >> x;}
	heapSort(v);
// descending order
	for (int x : v) {cout << x << " ";}

	return 0;
}