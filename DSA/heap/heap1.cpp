#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	Heap :-

	- Binary Tree
	- Complete Binary Tree Property
	- Heap Order Property

	Heap order property:
	parent priority > children priority

*/

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

	void pop() {
		swap(v[0], v[v.size() - 1]);
		v.pop_back();
		int i = 0;
		while (i < v.size()) {
			int s = 2 * i + 1;
			if ((2 * i + 2) < v.size() and v[2 * i + 1] > v[2 * i + 2]) s = 2 * i + 2;
			if (s >= v.size()) break;
			if (v[i] > v[s]) {
				swap(v[i], v[s]);
				i = s;
			}
			else {
				break;
			}
		}
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

// 11
// 1 7 3 8 4 2 6 5 9 11 13