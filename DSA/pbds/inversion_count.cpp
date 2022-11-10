#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        o_set;

int main() {

	FIO;
	oset s;
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		s.insert(t);
		ans += s.size() - s.order_of_key(t);
	}
	cout << ans << endl;
	return 0;
}