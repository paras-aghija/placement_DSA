#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

struct node {
	node *next[26];
	bool terminal;

	node() {
		for (int i = 0; i < 26; i++) {
			next[i] = NULL;
		}
		terminal = false;
	}
};

node *root;

void insert(string s) {
	node *curr = root;
	for (auto c : s) {
		if (curr->next[c - 'a'] == NULL) {
			curr->next[c - 'a'] = new node();
		}
		curr = curr->next[c - 'a'];
	}
	curr->terminal = true;
}

bool search(string s) {
	node *curr = root;
	for (auto c : s) {
		if (curr->next[c - 'a'] == NULL) {
			return false;
		}
		curr = curr->next[c - 'a'];
	}
	return curr->terminal;
}

int main() {

	FIO;
	root = new node();
	insert("magneto");
	insert("gautam");
	insert("anurag");
	insert("shaan");

	cout << search("magneto");
	cout << search("magn");
	cout << search("gautam");


	return 0;
}