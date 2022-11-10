#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int fibo(int n) {
	return (n == 0 or n == 1) ? n : fibo(n - 1) + fibo(n - 2);
}

int main() {

	FIO;
	// computing nth fibonacci term
	cout << fibo(8);
	return 0;
}
// 0 1 2 3 4 5 6 7  8
// 0 1 1 2 3 5 8 13 21