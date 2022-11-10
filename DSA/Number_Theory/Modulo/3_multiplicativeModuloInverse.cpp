#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


/*

	x = a
	Multiplicative inverse of x => 1/ab

	x = a and m
	find a number b such that (a.b)%m = 1
	b here is multiplicative modulo inverse of a with respect to m

	Example :-

	a = 6
	m = 7

	find b such that

	(a.b) % m = 1
	b = 6

	Proof :-

	(A.B) % m = 1
	(A.B) % m - 1 = 0
	(A.B) - 1 = Km

	(A.B) - Km = 1
	(A.B) + (-K)m = 1

	(A.B) + m(K') = 1

	Ax + By = 1 <= GCD(A,B)  == GCD(A,M)

	** Modulo inverse only exist if GCD(A,M) = 1

	From extended euclidean

	x = B
	y = K'

	We can find B using extended euclidean

*/


int x, y, GCD;

void extendedEuclid(int a, int b) {
// Base Case
	if (b == 0) {
		GCD = a;
		x = 1;
		y = 0;
		return;
	}

// Recursive Bottom Up
	extendedEuclid(b, a % b);
	int x1 = x;
	int y1 = y;
	x = y1;
	y = x1 - (a / b) * y1;
}


// Assume inverse exists
int inverseModulo(int a, int m) {
	// only possible if gcd is 1
	if (__gcd(a, m) != 1) {
		return -1;
	}
	extendedEuclid(a, m);
	;
	return (x + m) % m;
}


int main() {

	FIO;
	cout << inverseModulo(6, 7) << endl;
	cout << inverseModulo(8, 7) << endl;
	cout << inverseModulo(18, 7) << endl;

	return 0;
}