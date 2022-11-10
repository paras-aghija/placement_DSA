#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

class Person {
public:
	string name;
	int age;

	Person() {

	}

	Person(string n , int a) {
		name = n;
		age = a;
	}
};

class PersonCompare {
public:
	bool operator()(Person A, Person B) {
		return A.age < B.age;
	}
	// functor for pq to compare Person objects
};

int main() {

	FIO;
	int n;
	cin >> n;

	priority_queue<Person, vector<Person>, PersonCompare> pq;

	for (int i = 0; i < n; i++) {
		string n;
		int a;
		cin >> n >> a;
		Person p(n, a);
		pq.push(p);
	}

	while (!pq.empty()) {
		Person x = pq.top();
		cout << x.name << " " << x.age << endl;
		pq.pop();
	}

	return 0;
}

/*
5
A 8
B 12
C 11
D 17
E 15
*/