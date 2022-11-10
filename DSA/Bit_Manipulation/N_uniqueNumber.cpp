#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Unique Number 1
	all numbers in array are present twice except one, find number that occures once
	a^0 = a
	a^a = 0
	Numbers occuring twice will turn to 0

	Unique Nimber 2
	all numbers occure twice except 2 numbers


	Unique Number 3
	all numbers present thrice except one number

	arr = [3,3,2,1,1,1,3]

	3 -> 0 1 1
	3 -> 0 1 1
	2 -> 0 1 0
	1 -> 0 0 1
	1 -> 0 0 1
	1 -> 0 0 1
	3 -> 0 1 1
	-----------
		 0 4 6
		 %   3
	-----------
	2 <- 0 1 0

	We can design an algorithm where number are repeated n times

*/

void printv(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

void uniqueNumber1() {
	vector<int> arr = {1, 7, 1, 2, 3, 5, 2, 5, 7};
	int ans = 0;
	for (auto i : arr) {
		ans ^= i;
	}

	cout << ans << endl;
}

void uniqueNumber2() {
	vector<int> arr = {1, 1, 2, 3, 5, 2, 5, 7}; // uniqueL 3, 7
	// remove all numbers occuring twice
	int u = 0;
	for (auto i : arr) {
		u ^= i;
	}

	int temp = u;
	int p = 0;
	while ((temp & 1) == 0) {
		temp = temp >> 1;
		p++;
	}
	int a = 0, b = 0;
	for (auto i : arr) {
		if ((i >> p) & 1) {
			a ^= i;
		}
	}
	b = u ^ a;
	cout << min(a, b) << " " << max(a, b) << endl;
}

void uniqueNumber3() {
	vector<int> arr = {1, 1, 1, 2, 2, 2, 6};
	int n = 3;
	vector<int> v(64, 0);
	for (auto i : arr) {
		int x = i;
		int j = 0;
		while (x != 0) {
			v[j++] += x & 1;
			x = x >> 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 64; i++) {
		ans += (1 << i) * (v[i] % n);
	}
	cout << ans << endl;
}

int main() {

	FIO;
	uniqueNumber1();
	uniqueNumber2();
	uniqueNumber3();

	return 0;
}