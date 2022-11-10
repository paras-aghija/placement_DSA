#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

int MAXL = 1000005;
// vector<int> ps(MAXL,0);
bitset<1000005> ps; // memory optimised
vector<int> primes;
void primeSieve() {
	primes.push_back(2);
	ps[2] = 1;
	// marking all odd numbers initially as prime
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

// My Approach
void pf1(int n, set<int> &factors) {
	if (n == 1) {
		return;
	}
	for (auto i : primes) {
		if (n % i == 0) {
			factors.insert(i);
			pf1(n / i, factors);
			return;
		}
	}
}

// Naive Approach
void pf2(int n) {
	vector<pair<int, int>> factors;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n = n / i;
			}
			factors.push_back(make_pair(i, cnt));
		}
	}
	if (n != 1) {
		factors.push_back(make_pair(n, 1));
	}
	for (auto i : factors) {
		cout << i.first << " : " << i.second << endl;
	}
	cout << endl;
	ll ans = 1;
	for (auto i : factors) {
		ans = ans * (i.second + 1);
	}
	cout << "No of Divisors : " << ans << endl;
}

int main() {

	FIO;
	cout << "HEllow";
	// primeSieve();
	// for (int i = 1; i <= 20; i++) {
	// 	cout << i << " : " << ps[i] << endl;
	// }


	return 0;
}