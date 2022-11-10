#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


void multiply(int *a, int &n, int x) {
	int carry = 0;
	for (int i = 0; i < n; i++) {
		int product = a[i] * x + carry;
		a[i] = product % 10;
		carry = product / 10;
	}
	while (carry) {
		a[n] = carry % 10;
		carry /= 10;
		n++;
	}
}

void bigFactorial(int num) {
	int *a = new int[1000]();
	a[0] = 1;
	int n = 1;
	for (int i = 2; i <= num; i++) {
		multiply(a, n, i);
	}

	// print product
	for (int i = n - 1; i >= 0; i--) {
		cout << a[i];
	}
}

int main() {

	FIO;
	int n;
	cin >> n;
	bigFactorial(n);
	return 0;
}