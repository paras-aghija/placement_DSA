#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int pow(int a, int b) {
	if (b == 0) return 1;
	int x = pow(a, b / 2);
	int ans = x * x;
	if (b % 2) ans *= a;
	return ans;
}

int main() {

	FIO;
	cout << pow(2, 5) << endl;
	cout << pow(2, 8) << endl;

	return 0;
}