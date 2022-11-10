#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

/*

	A number is said to be almost prime if it have exactly 2 prime divisors
	6 => 2,3
	18 => 2,3

	Find number of almost prime numbers in range 1 to n
	1<=n<=3000

*/


int ans = 0;
const ll MAXL = 3005;
vector<int> ps(MAXL, 0);
void primeSieve() {
	for (ll i = 2; i < MAXL; i ++) {
		if (!ps[i]) {
			for (ll j = i; j < MAXL; j += i) {
				ps[j]++;
			}
		}
	}
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (ps[i] == 2) {ans++;}
	}
	cout << ans << endl;

}

int main() {

	FIO;
	primeSieve();

	return 0;
}