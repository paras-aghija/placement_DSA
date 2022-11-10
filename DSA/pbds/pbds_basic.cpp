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
        PBDS;
// for duplicate elements change int to pair<int,int>



int main() {

	FIO;
	PBDS st;
	st.insert(1);
	st.insert(3);
	st.insert(4);
	st.insert(10);
	st.insert(15);

	// find by order => kth largest element in log(n)
	for (int i = 0; i < st.size(); i++) {
		cout << i << " " << *st.find_by_order(i) << endl;
	}

	// similar to lower bound
	// no. of elements strictly smaller than 5 in log(n)time
	cout << st.order_of_key(5) << endl;


	return 0;
}