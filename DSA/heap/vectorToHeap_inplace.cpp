#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

Intuitive Tc:-

	Suppose we need to heapify worst case in each pass
	At each level following will be the complexities

	1 2 2^2 2^3 .... 2^h-1 = N
	Each node can travel up logN height at max in heapify operaton
	For n node Time complexity = O(nlogn)

*/

int main() {

	FIO;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// max heap
	for (int i = 1; i < n; i++) {
		int x = i;
		while (x > 0 and v[x] > v[(x - 1) / 2]) {
			swap(v[x], v[(x - 1) / 2]);
			x = (x - 1) / 2;
		}
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}



	return 0;
}