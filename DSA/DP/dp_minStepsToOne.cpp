#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	n => n/3 if n%3 == 0
	n => n/2 if n%2 == 0
	n => n-1
*/

void printv(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int recursive(int n) {
	if (n == 1) {
		return 0;
	}
	int c1 = (n % 3 == 0) ? recursive(n / 3) : INT_MAX;
	int c2 = (n % 2 == 0) ? recursive(n / 2) : INT_MAX;
	int c3 = recursive(n - 1);
	return 1 + min(c1, min(c2, c3));
}

vector<int> dp1(100);
int top_down(int n) {
	if (n == 1) {
		return 0;
	}

	if (dp1[n] != 0) {
		return dp1[n];
	}
	int c1 = (n % 3 == 0) ? recursive(n / 3) : INT_MAX;
	int c2 = (n % 2 == 0) ? recursive(n / 2) : INT_MAX;
	int c3 = recursive(n - 1);
	return dp1[n] = 1 + min(c1, min(c2, c3));
}

vector<int> dp2(100);
int bottom_up(int n) {
	static int pt = 2;
	for (int i = pt; i <= n; i++) {
		int c1, c2, c3;
		c1 = c2 = c3 = INT_MAX;
		if (i % 3 == 0) {
			c1 = dp2[i / 3];
		}
		if (i % 2 == 0) {
			c2 = dp2[i / 2];
		}
		c3 = dp2[i - 1];
		dp2[i] = 1 + min(c1, min(c2, c3));
	}
	return dp2[n];
}

int main() {

	FIO;
	int n;
	cin >> n;
	cout << recursive(n) << endl;
	cout << top_down(n) << endl;
	cout << bottom_up(n) << endl;



	return 0;
}