#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

class Fun {
public:
	void operator()(string s) {
		cout << "inside operator () " << s << endl;
	}
};

int main() {

	FIO;
	Fun f; // class object
	f("c++"); // overloaded operator similar to a function call
	// though f is an object but it is behaving like a function call
	// also known as functional object or functor

	return 0;
}