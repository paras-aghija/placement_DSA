#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;


// O(N)
bool isPrime1(int n) {
	if (n == 1) {return false;}
	if (n <= 3) {return true;}
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

// O(rootN)
bool isPrime2(int n) {
	if (n == 1) {return false;}
	if (n <= 3) {return true;}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

// Most optimised
bool isPrime3(int n)
{
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (n % 2 == 0 or n % 3 == 0) return false;
	int p = sqrt(n);
	for (int i = 5; i <= p; i = i + 6)
		if (n % i == 0 or n % (i + 2) == 0)
			return false;
	return true;
}

// primeSieve does precomputation in O(Nlog(log(N))) time
// gives prime in O(1) time
const ll MAXL = 10000005;
bitset<MAXL> ps;
void primeSieve() {
	ps[1] = 0;
	ps[2] = 1;
	// mark all odd places true
	for (ll i = 3; i < MAXL; i += 2) {
		ps[i] = 1;
	}

	// sieve
	for (ll i = 3; i < MAXL; i += 2) {
		if (ps[i] == 1) {
			// mark all multiples of i as not prime
			for (ll j = i * i; j < MAXL; j += i) {
				ps[j] = 0;
			}
		}
	}
}


int main() {

	FIO;
	primeSieve();
	for (int i = 1; i <= 20; i++) {
		cout << i << " -> " << ps[i] << endl;
	}
	return 0;
}