#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	Pattern : aaca
	Text : abaacadbacad

	Check if text contains pattern

	Brute force check for all substrings
	Use sliding window technique

	TC : O(n*m)

	n => text.length()
	m => pat.length()

*/

int main() {

	FIO;
	string pat, text;
	cin >> text;
	cin >> pat;

	for (int i = 0; i + pat.length() <= text.length(); i++) {
		if (text.substr(i, pat.length()) == pat) {
			cout << "Pattern Found at index " << i << endl;
		}
	}

	return 0;
}