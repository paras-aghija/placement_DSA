#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void dec(int n) {
	if (n == 0) return;
	cout << n << endl;
	dec(n - 1);
}

void inc(int n) {
	if (n == 0) return;
	inc(n - 1);
	cout << n << endl;
}

int main() {

	FIO;
	inc(5);
	cout << endl;
	dec(5);

	return 0;
}