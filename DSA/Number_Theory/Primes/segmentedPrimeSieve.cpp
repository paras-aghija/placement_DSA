#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

/*
	Generate prime numbers between two numbers m and n
	m,n -> 10^9
    |n-m| ~ 10^5

    we can only create sieve of max length 10^7

    m = 50 , n = 100
    We will create a sieve of size 50 only
    But 0th index => represents 50
    0th index => represents 100

	Store all primes upto root N i.e. 10^5
*/


const ll MAXL = 10000005;
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


void solve() {
	ll m, n;
	cin >> m >> n;
	bool ss[n - m + 1] = {0};
	for (auto x : primes) {
		if (x * x > n) {
			break;
		}
		ll start = (m / x) * x;
		if (x >= m and x <= n) {
			start = 2 * x;
		}

		for (ll i = start; i <= n; i += x) {
			ss[i - m] = 1; // 1 represents not prime in segmented sieve
		}
	}

	for (int i = m; i <= n; i++) {
		if (ss[i - m] == 0 and i != 1) {
			cout << i << endl;
		}
	}
}

int main() {

	FIO;
	primeSieve();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}