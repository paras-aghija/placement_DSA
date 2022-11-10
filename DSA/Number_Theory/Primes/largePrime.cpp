#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

/*

	Given n ~ 10^12/ 10^14
	Find whether n is prime or not
	Sieve can only be made upto 10^7

	for big numbers iterate divisors from 0 to root N

*/

const ll MAXL = 10000002;
bitset<MAXL> ps;
vector<ll> primes;
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

bool isPrime(ll no) {
	// O(1)
	if (no < MAXL) {
		return ps[no] == 1 ? true : false;
	}
	// O(root(N))
	else {
		for (auto i : primes) {
			if (i * i > no) {
				break;
			}
			if (no % i == 0) {
				return false;
			}
		}
	}
	return true;
}
int main() {

	FIO;
	primeSieve();
	ll n;
	cin >> n;
	cout << isPrime(n);

	return 0;
}

// Ten digit prime number : 2147483647