#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	Extended Euclid's Algorithm

	This helps to solve an equation of the form

	Ax + By = GCD(A,B)

	Applications :-

	1. Multiplicative Modulo Inverse
	2. Linear Diophantine Equations

	Base Case GCD => a,  y = 0

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

int main() {

	FIO;
	// 18x + 30y = GCD(18,30)
	extendedEuclid(18, 30);
	cout << x << " " << y << endl; // VALID

	return 0;
}