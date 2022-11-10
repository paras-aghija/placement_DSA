#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

/*

	1. Naive Approach
	2. Optimised Approach
	3. Sieve Based Approach

*/

const ll MAXL = 10005;
bitset<MAXL> ps;
vector<int> primes;
void primeSieve() {
	ps[1] = 0;
	ps[2] = 1;
	primes.push_back(2);
	for (ll i = 3; i < MAXL; i += 2) {
		ps[i] = 1;
	}

	for (ll i = 3; i < MAXL; i += 2) {
		if (ps[i] == 1) {
			primes.push_back(i);
			for (ll j = i * i; j < MAXL; j += i) {
				ps[j] = 0;
			}
		}
	}
}

// naive : loop from 2 to n
// O(n)

// optimised 1
// O(sqrt(N))
void pf1(int n) {
	int cnt = 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			cout << "(" << i << "^" << cnt << ") ";
		}
	}
	if (n != 1) {
		cout << "(" << n << "^" << 1 << ")";
	}
}

// Optimised 2
void pf2(int n) {
	for (auto x : primes) {
		if (x * x > n) {break;}
		if (n % x == 0) {
			cout << x << " ";
			while (n % x == 0) {
				n /= x;
			}
		}
	}
	if (n != 1) {
		cout << n << endl;
	}
}

const ll MAXL2 = 10005;
vector<int> ps2(MAXL2, 0);
void primeSieve2() {
	for (ll i = 2; i < MAXL2; i++) {
		if (ps2[i] == 0) {
			for (ll j = i; j < MAXL2; j += i) {
				ps2[j]++;
			}
		}
	}
}

int main() {

	FIO;
	primeSieve();
	primeSieve2();
	pf2(84);
	pf1(84);
	cout << endl;
	cout << ps2[84];

	return 0;
}