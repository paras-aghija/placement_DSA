#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int f(int n) {
	if (n == 1 or n == 2) return n;
	return f(n - 1) + (n - 1) * f(n - 2);
	//alone   //chose 1 among n-1 and find possible ways for n-2 people
}

int main() {

	FIO;
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}