#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
const ll mod = 1e9 + 7;
const ll p = 31;
using namespace std;

/*
	RABIN KARP - 1

	We will convert a string to integer

	text: abaacdeabd
	pat : aacd

	pathash = hash(pat) => [ a*p0 + a*p1 + c*p2 + d*p3 ] % m

	find which 4 lenght window gives hash eqal to pathash
	We will use a rolling hash here


	Window 1 : abaa
	h_now = [ a*p0 + b*p1 + a*p2 + a*p3 ] % m


	window 2: baac
	h_now = [ b*p0 + a*p1 + a*p2 + c*p3 ] % m

	Steps:-

	1. Subtract (c*p0) from h_prev => Remaining hash [ b*p1 + a*p2 + a*p3 ]
	2. Divide the remaining hash by p => [ b*p0 + a*p1 + a*p2 ]
	3. Add new element with appropriate pow => [ b*p0 + a*p1 + a*p2 + c*p3]

	Note :-

	(a/p)%m => (a*(p^-1))%m

	We can find p^-1 using fermats little theorem

	FERMATS LITTLE THEOREM

	(a^p-1) = 1 (mod p)
	(a^p-2) = (a^-1) (mod p)
	(a^-1) = (a^p-2) (mod p)

*/

ll powr(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1ll) {
			res *= a;
			res %= mod;
		}
		b /= 2;
		a *= a;
		a %= mod;
	}
	return res;
}

ll inv(ll a) {
	// a^-1 %  p
	return powr(a, mod - 2);
}

ll hash_fn(string s) {
	ll p_power = 1;
	ll hashval = 0;
	for (auto c  : s) {
		hashval += p_power * (c - 'a' + 1);
		p_power *= p;
		p_power %= mod;
		hashval %= mod;
	}
	return hashval;
}





int main() {

	FIO;
	string text, pat;
	cin >> text;
	cin >> pat;

	ll pat_hash = hash_fn(pat);
	int n = text.length();
	int m = pat.length();

	ll text_hash = hash_fn(text.substr(0, m));

	// cout << pat_hash << endl;
	// cout << text_hash << endl;

	if (text_hash == pat_hash) {
		cout << "Found at 0" << endl;
	}

	for (int i = 1; i + m < n; i++) {
		ll new_hash = text_hash;
		// [i-1]th character being removed in the ith window
		// Step 1
		new_hash -= (text[i - 1] - 'a' + 1);
		new_hash = (new_hash + mod) % mod;

		// Step 2
		new_hash *= inv(p);
		new_hash %= mod;


		// Step 3
		new_hash += (text[i + m - 1] - 'a' + 1) * powr(p, m - 1);
		new_hash %= mod;

		// cout << new_hash << endl;;

		if (new_hash == pat_hash) {
			cout << "Found at " << i << endl;
		}

		text_hash = new_hash;

	}



	return 0;
}