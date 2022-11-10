#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

/*
	Given an integer n find 3 distinct integers a,b,c such that
	2<=a,b,c and a.b.c = n

	Calculate prime factors of a number
	if number has more than 3 prime factors then ans is YES

	but
	64 => 2^6 => 2.4.8 i.e. a,b,c can be formed

	Compute prime factors

	1. Factors >= 3 YES
	2. Factors = 2 fin c = n/(a.b) compare c with a and b
	3. Factors = 1 and power >= 6 then YES else NO
*/

int main() {

	FIO;


	return 0;
}