#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	GCD/HCF of a = 12, b = 20 => 4
	Brute force iterate from 1 to min(a,b)

	Optimised: Euclids algorithm

	GCD(a,b) = GCD(b,a%b)
	GCD(a,0) = a

	Intuition in image

	LCM = (a*b)/GCD(a,b)

	Time Complexity:  O(logn)

*/

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}
int main() {

	FIO;
	cout << gcd(20, 12);

	return 0;
}