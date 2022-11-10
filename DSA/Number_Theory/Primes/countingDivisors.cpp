#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

/*
	Find number of divisors of given number n

	60 = 2^2 x 3^1 x 5^1

	2^2 => 2^0 or 2^1 or 2^2 (3 ways)
	3^1 => 2 ways
	5^1 => 2 ways

	Total = 3*2*2 = 12 Ways
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

int pf2(int n) {
	int ans = 1;
	for (auto x : primes) {
		if (x * x > n) {break;}
		if (n % x == 0) {
			int cnt = 0;
			while (n % x == 0) {
				n /= x;
				cnt++;
			}
			ans *= (cnt + 1);
		}
	}
	if (n != 1) {
		ans *= 2;
	}
	return ans;
}

int main() {

	FIO;
	primeSieve();
	cout << pf2(60);

	return 0;
}