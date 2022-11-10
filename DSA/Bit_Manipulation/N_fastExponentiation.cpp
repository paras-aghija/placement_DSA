#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Given two numbers a, n
	compute a^n

	a^5 => a^(101)

	a^4 . a^0 . a^1
	max number of set bits in a number N => logN
	Time Complexity: o(logN)
*/

int pow(int a, int n) {
	int ans = 1;
	while (n > 0) {
		int lastbit = (n & 1);
		if (lastbit) {
			ans = ans * a;
		}
		a = a * a;
		n = n >> 1;
	}
	return ans;
}



int main() {

	FIO;
	int a, b;
	cin >> a >> b;
	cout << pow(a, b);

	return 0;
}