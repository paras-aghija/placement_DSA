#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	There are bn white dots and n black dots, equally spaced
	You want to connect each white dot with some one black dot
	with minimum total length of the wire
	Find the length of the wire needed

	Inputs :-

	white dot positions = []
	black dot positions = []

	Greedy Approach : find nearest black dot for each white dot

*/

int main() {

	FIO;
	int n;
	cin >> n;
	vector<int> white(n), black(n);
	for (auto &x : white) {
		cin >> x;
	}
	for (auto &x : black) {
		cin >> x;
	}
	sort(white.begin(), white.end());
	sort(black.begin(), black.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(white[i] - black[i]);
	}
	cout << ans;

	return 0;
}