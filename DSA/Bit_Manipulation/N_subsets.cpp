#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void filterChar(int n, string s) {
	int j = 0;
	while (n) {
		int lb = (n & 1);
		if (lb) {
			cout << s[j];
		}
		j++;
		n = n >> 1;
	}
	cout << endl;
}

void subsets(string s) {
	int i = 0;
	for (int i = 0; i < (1 << s.length()); i++) {
		filterChar(i, s);
	}
}

int main() {

	FIO;
	string s;
	cin >> s;
	subsets(s);

	return 0;
}