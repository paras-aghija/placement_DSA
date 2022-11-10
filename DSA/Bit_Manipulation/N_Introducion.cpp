#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	Bit manipulation Introduction

	Basic Operators:


	Binary Operators:-

	| OR
	& AND
	^ XOR (1^1 = 0^0 = 0)

	Other Operators:-

	~/! NOT (~1 = 0)
	<< Leftshift	(1<<3 = 8)	(Multiplication by 2^x)
	>> RightShift	(8>>3 = 1)	(Division by 2^x)

	XOR Properties :-

	a^a = 0
	a^0 = a


*/

int getBit(int n, int i) {
	return (n & (1 << i)) > 0;
}

void setBit(int &n, int i) {
	n = n | (1 << i);
}

void clearBit(int &n, int i) {
	n = n & (~(1 << i));

}

void toggleBit(int &n, int i) {
	n = n ^ (1 << i);
}


void clearLastIBits(int &n, int i) {
	int mask = (~0) << i;
	n = n & mask;
}

void clearBitItoJ(int &n, int i, int j) {
	int mask1 = ~((~0) << (j - i + 1));
	int mask2 = ~(mask1 << i);
	n = n & mask2;
}

void oddEven() {
	// if last bit is 1 then its odd else even
	cout << "OddEven: ";
	int n = 6;
	(n & 1) ? cout << "ODD" << endl : cout << "EVEN" << endl;
}


void getSetBits() {
	int n = 5;
	cout << "GetBit: " << getBit(n, 2) << endl;
	cout << n << endl;
	setBit(n, 1);
	cout << n << endl;
	toggleBit(n, 2);
	cout << n << endl;
	clearBit(n, 0);
	cout << n << endl;
	cout << "GetBit: " << getBit(n, 2) << endl;

}

void bitRange() {
	int n = 15;
	cout << n << endl;
	clearLastIBits(n, 2);
	cout << n << endl;
	int x = 31;
	cout << x << endl;
	clearBitItoJ(x, 2, 4);
	cout << x << endl;
}

int main() {

	FIO;
	oddEven();
	getSetBits();
	bitRange();

	return 0;
}