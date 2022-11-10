#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	Compute (a^b)%m

	- Brute Force : O(b)
	- Optimised   : O(logb)

	Recursion + Bitmask

	3 ^ 5 => 3 ^ (1 	0 	 1)
				3^4 + 3^2 + 3^1

*/

#define ll long long
#define mod 1000000007

ll fastModExp(ll a, ll b, ll m) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) {
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b = b >> 1;
	}
	return res;
}

int main() {

	FIO;
	cout << fastModExp(5, 3, 100 );

	return 0;
}