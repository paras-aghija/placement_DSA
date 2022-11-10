#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Trie DS => K-ary tree
	Every node can have a max of 26 children

	Pattern : aaca
	Text : abacadbacad

	Check if text contains pattern

	Approach
	Insert all siffixes of text into the trie

	Eg :-

	abaac

	abaac
	baac
	aac
	ac
	c

	All suffixes will contain all the information
	starting from a particualar position
*/
struct node {
	node *next[26];
	node() {
		for (int i = 0; i < 26; i++) {
			next[i] = NULL;
		}
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
}

bool search(string s) {
	node *curr = root;
	for (auto c : s) {
		if (curr->next[c - 'a'] == NULL) {
			return false;
		}
		curr = curr->next[c - 'a'];
	}
	return true;
}

int main() {

	FIO;
	root = new node();
	string text, pat;
	cin >> text;
	cin >> pat;
	int n = text.length();
	int m = pat.length();

	for (int i = 0; i < n; i++) {
		insert(text.substr(i));
	}

	if (search(pat)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}