#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Problem link: https://www.spoj.com/problems/EXPEDI/ (Hard)
*/

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {

	FIO;
	int n, t, x, d, f, D, F, prev = 0;
	cin >> t;
	while (t--) {
		int flag = 0;
		int ans = 0;
		vector<pair<int, int>>v;
		priority_queue<int> pq;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> d >> f;
			v.push_back(make_pair(d, f));
		}

		sort(v.begin(), v.end(), compare);

		cin >> D >> F;

		for (int i = 0; i < n; i++) {
			v[i].first = D - v[i].first;
		}

		prev = 0;
		x = 0; //current city
		while (x < n) {
			// check fuel to go to next city
			if (F >= v[x].first - prev) {
				F -= v[x].first - prev;
				pq.push(v[x].second);
				prev = v[x].first;
			}
			else {
				// check if there were some fuelling stations which you could have used
				if (pq.empty()) {
					flag = 1;
					break;
				}
				else {
					// refuel the truck with a fueling station enxountered back having max capacity
					F += pq.top();
					pq.pop();
					ans++;
					continue;
				}
			}
			x++;
		}
		// n fuel stations travelled next point is town
		if (flag == 1) {
			cout << -1 << endl;
			continue;
		}

		D = D - v[n - 1].first;
		if (F >= D) {
			cout << ans << endl;
			continue;
		}
		else {
			while (F < D) {
				if (pq.empty()) {
					flag = 1;
					break;
				}
				F += pq.top();
				pq.pop();
				ans++;
			}
		}

		if (flag == 1) {
			cout << -1 << endl;
			continue;
		}
		else {
			cout << ans << endl;
			continue;
		}
	}


	return 0;
}