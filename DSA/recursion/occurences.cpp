#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int f_occ(int *a, int n, int key) {
	if (n == 0) return -1;
	if (a[0] == key) { return 0; }
	int res = f_occ(a + 1, n - 1, key);
	return (res == -1) ? -1 : res + 1;
}

int l_occ(int *a, int n, int key) {
	if (n == 0) return -1;
	int res = l_occ(a + 1, n - 1, key);
	if (res != -1) {return res + 1;}
	if (a[0] == key) { return 0; }
	return -1;
}

void all_occ(int *a, int i, int n, int key) {
	if (i == n) return;
	if (a[i] == key) cout << i << " ";
	all_occ(a, i + 1, n, key);
}

int main() {

	FIO;
	int n;
	cin >> n;
	int v[n];
	for (int i = 0; i < n; i++) cin >> v[i];
	cout << f_occ(v, n, 3) << endl;
	cout << l_occ(v, n, 3) << endl;
	all_occ(v, 0, n, 3);
	return 0;
}