#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	s1 = aabcc
	s2 = dbbca

	Interleaving : Final string should contain all the
	characters of s1 and s2 and individual ordering
	must be preserved

		   ||    || | -> s1 tags
	final: aadbbcbcac
			 ||||  |  -> s2 tags

	PROBLEM:-
	you are given 3 strings s1,s2,s3
	If s3 can be made by interleaving s1 and s2

	APPROACH:-

	s3.length() != s1.length() + s2.length() => false

*/

string s1, s2, s3;

bool interleaving(int i, int j, int k) {
	if ((s1.length() + s2.length()) != s3.length()) {
		return false;
	}
	if (i == s1.length()) {
		return s2.substr(j) == s3.substr(k);
	}
	if (j == s2.length()) {
		return s1.substr(i) == s3.substr(k);
	}

	if ((s1[i] == s3[k] and interleaving(i + 1, j, k + 1)) or
	        (s2[j] == s3[k] and interleaving(i, j + 1, k + 1))) {
		return true;
	}
	return false;
}

int main() {

	FIO;

	s1 = "aabcc";
	s2 = "dbbca";
	s3 = "aadbbcbcac";

	// cin >> s1;
	// cin >> s2;
	// cin >> s3;

	cout << s1 << endl << s2 << endl << s3 << endl;

	cout << interleaving(0, 0, 0);

	return 0;
}