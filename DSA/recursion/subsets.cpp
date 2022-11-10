#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

string s, cstring = "";
void subset(int i) {
	if (i == s.length()) {
		cout << cstring << endl;
		return;
	}
	// dont include ith index
	subset(i + 1);
	// include ith index
	cstring;
	cstring.push_back(s[i]);
	subset(i + 1);
	cstring.pop_back();
}

int main() {

	FIO;
	cin >> s;
	subset(0);
	return 0;
}