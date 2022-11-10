#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

class Heap {
	vector<int> v;
public:

	void push(int x) {
		v.push_back(x);
		int i = v.size() - 1;
		while (i > 0 and v[(i - 1) / 2] > v[i]) {
			swap(v[i], v[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	int top() {
		return v[0];
	}

	void heapify(int idx) {
		int l = 2 * idx + 1;
		int r = 2 * idx + 2;
		int min_idx = idx;
		if (l < v.size() and v[l] < v[idx]) {
			min_idx = l;
		}
		if (r < v.size() and v[r] < v[min_idx]) {
			min_idx = r;
		}
		if (min_idx != idx) {
			swap(v[idx], v[min_idx]);
			heapify(min_idx);
		}
	}

	void pop() {
		swap(v[0], v[v.size() - 1]);
		v.pop_back();
		heapify(0);

	}

	bool empty() {
		return v.size() == 0;
	}

	void display() {
		for (auto x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
};

int main() {

	FIO;
	Heap h;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		h.push(t);
		// h.display();

	}

	while (!h.empty()) {
		cout << h.top() << " ";
		h.pop();
	}

	return 0;
}
