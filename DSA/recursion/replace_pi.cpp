#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// xpighpilmpipi => x3.14gh3.14lm3.143.14
string ans = "";
void replace(string &s, int i) {
	if (i == s.length()) return;
	if (s[i] == 'p' and (i + 1) != s.length() and s[i + 1] == 'i') {
		ans += "3.14";
		replace(s, i + 2);
		return;
	}
	ans += s[i];
	replace(s, i + 1);
}
int main() {

	FIO;
	string s;
	cin >> s;
	replace(s, 0);
	cout << ans;
	return 0;
}