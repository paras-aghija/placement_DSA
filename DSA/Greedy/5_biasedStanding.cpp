#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

/*

	n teams
	Each team gives their preferred rank
	badness is sum of all teams (preferred rank - actual rank)
	return badness

	to minimise badness assign rank that is closest avaialable

	NOTE:

	We can use counting sort for this

*/

void solve() {
	ll n;
	cin >> n;
	string s;
	vector<ll>v(n);
	for (auto &x : v) {
		cin >> s >> x;
	}
	sort(v.begin(), v.end());
	ll bad = 0;
	for (int i = 0; i < n; i++) {
		bad += abs(i + 1 - v[i]);
	}
	cout << bad << endl;
}


void solve2() {
	ll n;
	cin >> n;
	string s;
	ll t;
	vector<ll>v(n, 0);
	for (auto &x : v) {
		cin >> s >> t;
		v[t]++;
	}

	ll bad = 0;
	int j = 0;
	for (int i = 1; i <= n; i++) {
		while (v[j] == 0) {
			j++;
		}
		bad += abs(i - j);
		v[j]--;
	}
	cout << bad << endl;
}

int main() {

	FIO;
	ll t;
	cin >> t;
	while (t--) {
		solve2();
	}


	return 0;
}