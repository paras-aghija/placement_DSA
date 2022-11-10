#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, tno = 0;
string cstring = "";
void brackets(int obc, int cbc) {
	if (cbc == n and obc == n) {
		// process cstring
		tno++;
		cout << cstring << endl;
	}
	// can we push (
	if (obc < n) {
		cstring.push_back('(');
		brackets(obc + 1, cbc);
		cstring.pop_back();
	}
	if (cbc < obc) {
		cstring.push_back(')');
		brackets(obc, cbc + 1);
		cstring.pop_back();
	}
}

int main() {

	FIO;
	cin >> n;
	brackets(0, 0);
	cout << tno << endl;
	return 0;
}