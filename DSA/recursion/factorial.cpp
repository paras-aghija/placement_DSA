#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int fact(int n) {
	return (n == 1) ? 1 : n * fact(n - 1);
}

int main() {

	FIO;
	cout << fact(6);

	return 0;
}