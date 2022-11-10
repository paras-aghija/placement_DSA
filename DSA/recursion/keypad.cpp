#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> v(100);
int n;
string cstring;
vector<string> keypad = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
void fun(int i) {
	if (i == n) {
		cout << cstring << endl;
		return;
	}
	for (char c : keypad[v[i]]) {
		cstring.push_back(c);
		fun(i + 1);
		cstring.pop_back();
	}
}

int main() {

	FIO;
	cin >> n;
	for (int &x : v) cin >> x;
	fun(0);
	return 0;
}