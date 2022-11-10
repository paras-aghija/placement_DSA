#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

Q1. Find the number of boolean strings of
of length N with no consecutive one's
FIBONACCI RECURRENCE QUESTION

Q2. Find number of ways to build wall of size
2 x N, with bricks of size 1x2 and 2x1
FIBONACCI RECURRENCE QUESTION

Q3. Ladder problem: Boy can jump either 2 step
or 2 step find number of ways to reach the nth
step
FIBONACCI RECURRENCE QUESTION


Ways to compute fibonacci

- Recursion : 2^N
- Top down DP : O(N)
- Bottom up DP : O(N)
- DP with space optimisation: O(N) O(1) space
- Matrix Exponentation: O(logN)
- Binnet's Formula: (phi^n - (-phi)^-n)/root(5) : O(1) time only for small values
- Codeforces hack: Derrived from matrix exponentation
	O(logn loglogn)

*/

#define long long long
const long M = 1000000007; // modulo
map<long, long> F;

long f(long n) {
	if (F.count(n)) return F[n];
	long k = n / 2;
	if (n % 2 == 0) { // n=2*k
		return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
	}
}



int main() {

	FIO;
	F[0] = F[1] = 1;
	for (int i = 1; i <= 20; i++) {
		cout << f(i) << endl;
	}
	return 0;
}