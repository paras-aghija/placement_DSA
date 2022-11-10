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

void pf1(int n, vector<pair<int, int>>
         &factors) {
	if (n == 1) {
		return;
	}
	for (auto i : primes) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			factors.push_back(make_pair(i, cnt));
		}
	}
}

int main() {

	FIO;
	primeSieve();
	int t;
	cin >> t;
	while (t--) {
		int n;
		vector<pair<int, int>> factors;
		cin >> n;
		pf1(n, factors);
		if (factors.size() == 1) {
			if (factors[0].second < 6) {
				cout << "NO" << endl;
			}
			else {
				int a = factors[0].first;
				int b = factors[0].first * factors[0].first;
				int c = n / (a * b);
				cout << "YES" << endl;
				cout << a << " " << b << " " << c << endl;
			}
		}\
		else if (factors.size() == 2) {
			int a = factors[0].first;
			int b = factors[1].first;
			int c = n / (a * b);
			if (c == a or c == b or c == 1) {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;

				cout << a << " " << b << " " << c << endl;
			}
		}
		else {
			int a = factors[0].first;
			int b = factors[1].first;
			int c = n / (a * b);
			cout << "YES" << endl;

			cout << a << " " << b << " " << c << endl;

		}


	}


	return 0;
}