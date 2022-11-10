#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	number to spelling
	2048 => two zero four eight
*/

string word[10] = { "zero", "one", "two", "three", "four", "five",
                    "six", "seven", "eight", "nine"
                  };

void spell(int n) {
	if (n == 0) return;
	spell(n / 10);
	cout << word[n % 10] << " ";
}

int main() {

	FIO;
	spell(2048);
	return 0;
}