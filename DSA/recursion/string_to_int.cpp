#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int str_to_int(string &s, int n) {
	if (n == 1) {
		return s[0] - '0';
	}
	int x = str_to_int(s, n - 1);
	return (10 * x) + (s[n - 1] - '0');
}

int main() {

	FIO;
	string s;
	cin >> s;
	// stl function
	cout << stoi(s) + 3 << endl;
	cout << str_to_int(s, s.length()) + 13;

	return 0;
}