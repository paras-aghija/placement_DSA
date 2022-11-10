#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	a = {1,5,2,6,3,0}
	inversions
	(1,0)
	(5,3)
	(5,2)
	(5,0)
	(2,0)
	(6,0)
	(6,3)
	(3,0)

	8 pairs

	Brute force n^2

	Efficient approach => divide and conquer
	{1,5,2}  {6,3,0}
	 X inv    Y inv
	 (5,2)	  (6,0)
	 		  (6,3)
	 		  (3,0)

	 find cross inversions of X and Y
	 Sort the array allongside
	 {1,2,5} {0,3,6}
	  i 	  j

	  push b[j] (0) in c => making (a.size()-i) inversion pairs : 3
	  push a[i] (1)
	  push a[i] (2)
	  push b[j] (3) in c =>  making (a.size()-i) inversion pairs : 1

	  Cross inversions = 4

	  return X + Y + CrossInversions
*/

void printv(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int merge(vector<int> &a, int s, int e) {
	int mid = (s + e) / 2;
	int i = s, j = mid + 1, k = s;
	vector<int> temp(10000);
	int cnt = 0; // cross inversion count
	while (i <= mid and j <= e) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			cnt += mid - i + 1;
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= e) {
		temp[k++] = a[j++];
	}
	for (int i = s; i <= e; i++) {
		a[i] = temp[i];
	}
	return cnt;
}

int inversion_count(vector<int> &v, int s, int e) {
	if (s >= e) {
		return 0;
	}
	int mid = (s + e) / 2;
	int x = inversion_count(v, s, mid);
	int y = inversion_count(v, mid + 1, e);
	int z = merge(v, s, e);
	return x + y + z;
}

int main() {

	FIO;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	cout << inversion_count(v, 0, n - 1) << endl;
	printv(v);
	return 0;
}