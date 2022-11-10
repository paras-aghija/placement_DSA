#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n;
vector<int> v(100);
string cstring = "";

void fun(int i, bool iv) {
	if (i == n) {
		if (!iv) return;
		cout << cstring << endl;
		return;
	}

	// consider current index as individual
	if (iv) {
		cstring.push_back('a' + v[i] - 1);
		fun(i + 1, 1);
		cstring.pop_back();
	}
	// pairup current index with next
	if (iv) {
		fun(i + 1, 0);

	}

	// current index is pairedup with previous
	if (iv == 0 and 10 * v[i - 1] + v[i] <= 26) {
		cstring.push_back('a' + (10 * v[i - 1] + v[i]) - 1);
		fun(i + 1, 1);
		cstring.pop_back();
	}
}


int main() {

	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	fun(0, 1);

	return 0;
}