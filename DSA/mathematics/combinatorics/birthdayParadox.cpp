#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
What is the minimum number of people that would
be present in a hall so that there is 50% chance
of two people of having same birthday

*/

int main() {

	FIO;
	float x = 1.0;
	// x denotes probability of 2 people having
	// different birthday
	int people = 0;
	int num = 365, den = 365;

	float p;
	cin >> p;
	if (p == 1.0) {
		cout << 366 << endl;
		return 0;
	}
	while (x > 1 - p) {
		x *= ((float)num / den);
		num--;
		people++;
	}
	cout << people << endl;
	return 0;
}