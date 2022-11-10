#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int make_change(vector<int> coins, int money) {
	int ans = 0;
	while (money > 0) {
		int idx = upper_bound(coins.begin(), coins.end(), money) - 1 - coins.begin();
		cout << coins[idx] << " -> ";
		money -= coins[idx];
		ans++;
	}
	return ans;
}

int main() {

	FIO;
	int n;
	cin >> n;

	vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int ans = make_change(coins, n);
	cout << "\nCoins needed : " << ans << endl;
	return 0;
}