#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Approach 1 : Backtracking
	Approach 2 : Backtracking + Bitsets
	Approach 3 : Backtracking + Bitmasking (Most Efficient)

	Generate a boolean bitmask (boolean vector) for each row
	n&(-n) => bitmask with last set bit
	n = 001010
	(-n) = 110101 + 1 = 110110
	p = n&(-n) = 000010

	To remove last set bit
	n = n&(n-1) OR n-p
	n => 001000
*/

int ans = 0, DONE ;

// rm => rowmask
// ldm => left diagonal mask
// rdm => right diagonal mask
void solve(int rm, int ldm, int rdm) {
	if (rm == DONE) {
ans++:
		return;
	}
}

int main() {

	FIO;
	int n;
	cin >> n;
	DONE = (1 << n) - 1;

	return 0;
}