#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

void decimalToBinary(int n) {
	ll ans = 0;
	ll p = 1;
	while (n) {
		ans += p * (n & 1);
		n = n >> 1;
		p *= 10;
	}
	cout << ans << endl;
}

int main() {

	FIO;
	decimalToBinary(12);

	return 0;
}