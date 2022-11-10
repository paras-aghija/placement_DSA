#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define setbits(x)			__builtin_popcountll(x)
#define tzbits(x)			__builtin_clzll(x)
#define lzbits(x)			__builtin_ctzll(x)
#define parity(x)			__builtin_parity(x)
using namespace std;

/*

	Find number of set bits in binary form of a number

	Brute Force: O(total number of bits)
	Optimised: O(number of set bits)

*/

int bruteForce(int n) {
	int ans = 0;
	while (n) {
		ans += n & 1;
		n = n >> 1;
	}
	return ans;
}

int optimised(int n) {
	int ans = 0;
	while (n) {
		ans++;
		n = n & (n - 1);
	}
	return ans;
}


int main() {

	FIO;
	int n;
	cin >> n;
	cout << bruteForce(n) << endl;
	cout << optimised(n) << endl;
	cout << setbits(n) << endl;		// Inbuilt method defined above
	cout << parity(5) << endl;		// contains even number of set bits
	cout << parity(7) << endl;		// contains odd number of set bits

	cout << tzbits(16) << endl;		// gives trailing zeros (64-5)
	cout << lzbits(32) << endl;		// leading zeros (..000100000 <= 32)

	return 0;
}

