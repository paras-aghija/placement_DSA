#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

/*

	Map each char to integer
	a=1
	b=2
	..
	z=26

	Take some prime p

	hash value =
		sum [ { (s[i]-'a'+1)*(p^i) } % mod ]

*/

ll hash_fn(string s) {
	ll p = 31, m = 1e9 + 7;
	ll p_power = 1;
	ll hashval = 0;
	for (auto c  : s) {
		hashval += p_power * (c - 'a' + 1);
		p_power *= p;
		p_power %= m;
		hashval %= m;
	}
	return hashval;
}

int main() {

	FIO;
	cout << hash_fn("abab");

	return 0;
}