#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> dp1(1000005);
vector<int> dp2(1000005);


int fibonacci(int n) {
	if (n == 1 or n == 0) {
		return n;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int top_down(int n) {
	if (n == 1 or n == 0) {
		return n;
	}

	if (dp1[n] != 0) {
		return dp1[n];
	}

	return dp1[n] = fibonacci(n - 1) + fibonacci(n - 2);
}


int bottom_up(int n) {
	static int start = 2;
	if (n <= start) {
		return dp2[n];
	}

	while (start <= n) {
		dp2[start] = dp2[start - 1] + dp2[start - 2];
		start++;
	}
	return dp2[n];
}

int bu_spaceOptimised(int n) {
	int a = 0;
	int b = 1;
	int c;
	for (int i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main() {

	FIO;
	int n;
	cin >> n;
	dp2[0] = 0;
	dp2[1] = 1;
	cout << "Recursive : " << fibonacci(n) << endl;
	cout << "Top Down : " << top_down(n) << endl;
	cout << "Bottom Up : " << bottom_up(n) << endl;
	cout << "Bottom Up Space Optimised : " << bu_spaceOptimised(n) << endl;

	return 0;
}