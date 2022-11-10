#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	If A and B are two disjoint sets (have nothing in common)
	then (A U B) = |A| + |B|

	If they are not disjoint
	(A U B) = |A| + |B| + (A ∩ B

	These formula can be written for any given number of sets)

	PROBLEM :-
	How many numbers  < 1000 and they are divisible by 2, 3, 5

	1...999 divisible by 2 : [999/3] = 499
	1...999 divisible by 3 : [999/3] = 333
	1...999 divisible by 5 : [999/5] = 199

	|2 U 3 U 5| = |2| + |3| + |5|
				- |2 ∩ 3| - |2 ∩ 5| - |3 ∩ 5|
				+ |2 ∩ 3 ∩ 5| = 733

	1...999 divisible by 6 : [999/6] = 166		|2 ∩ 3|
	1...999 divisible by 10: [999/10] = 99		|2 ∩ 5|
	1...999 divisible by 15: [999/15] = 66		|3 ∩ 5|

	1...999 divisible by 30: [999/10] = 33		|2 ∩ 3 ∩ 5|

*/

int subans(int n, vector<int> v, int x) {
	if (n == 0) {
		return 0;
	}
	int j = 0;
	int t = 1, l = 0;;
	while (n) {
		int lastbit = (n & 1);
		if (lastbit) {
			t *= v[j];
			l++;
		}
		n = n >> 1;
		j++;
	}
	if (l % 2) {
		return x / t;
	}
	else {
		return (-1 * (x / t));
	}
}

void fun(int x, vector<int> v) {
	int n = v.size();
	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		ans += subans(i, v, x - 1);
	}
	cout << ans << endl;
}

int main() {

	FIO;
	vector<int> arr = {2, 3, 5};
	int x = 1000;
	fun(x, arr);

	return 0;
}