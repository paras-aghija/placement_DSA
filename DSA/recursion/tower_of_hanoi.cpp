#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void move(int n, char src, char helper,  char dest) {
	if (n == 0) return;
	// rec move n-1 discs from src to helper
	move(n - 1, src, dest, helper);
	cout << "Move " << n << " " << src << " -> " << dest << endl;
	move(n - 1, helper, src, dest);
}

int main() {

	FIO;
	int n;
	cin >> n;
	move(n, 'A', 'B', 'C');

	return 0;
}