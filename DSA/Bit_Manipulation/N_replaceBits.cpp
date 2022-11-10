#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	you are given 2 integers n and m and 2 bit positions i and j
	write a function to set all bits between i and j in n equal to m

	EXAMPLE:-

	n = 10000000000
	m = 10101
	i = 2
	j = 6

	OUTPUT: n = 10001010100

*/

void clearBitItoJ(int &n, int i, int j) {
	int mask1 = ~((~0) << (j - i + 1));
	int mask2 = ~(mask1 << i);
	n = n & mask2;
}

void fun(int &n, int m, int i, int j) {
	// clear bits from i to j
	clearBitItoJ(n, i, j);
	// create mask with m at appropriate position
	int mask = m << i;
	n = n | mask;
}

int main() {

	FIO;
	int n, m;
	cin >> n >> m;
	int i, j;
	cin >> i >> j;
	fun(n, m, i, j);
	cout << n << endl;
	return 0;
}

// 1000000000	(1024)
// 11
// 3 4
// 1000011000	(1048)
