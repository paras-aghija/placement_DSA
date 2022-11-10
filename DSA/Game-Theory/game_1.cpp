#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	Game 1

	There is a pile of coins and there are 2 players A, B.
	Each player can remove either 1 or 2 coins.
	Players take alternating turns
	The player to pick last coin wins
	A starts the game

	N = 1 winner is A (W)
	N = 2 winner is A (W)
	N = 3 winner is B (L)
	N = 4 winner is A (W)
	N = 5 winner is A (W)
	N = 6 winner is B (L)

	N = 6 :-
	A picks 1 B picks 2 remain 3
	A picks 2 B picks 1 remain 3

	N%3 == 0 is a loosing state for player A
	rest all values are winning state

*/

int main() {

	FIO;
	int n;
	cin >> n;
	(n % 3 == 0) ? cout << 'B' : cout << 'A';

	return 0;
}