#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Wall : 4 x N
	Bricks : 1 x 4 OR 4 x 1
	N. of ways to build the wall
*/
int n;
int f(int i) {
	// cout << "f:" << i << endl;
	if (i == n) return 1;
	int ans = 0;
	//op1 vertical placement]
	ans += f(i + 1);
	// cout << "f:" << i << endl;

	//op2 horizontal placement
	if ((i + 4) <= n) {
		ans += f(i + 4);
	}
	return ans;

}

int main() {

	FIO;
	cin >> n;
	cout << f(0);

	return 0;
}