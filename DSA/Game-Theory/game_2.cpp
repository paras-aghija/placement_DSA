#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	Game 2 : Finders Keepers Game

	A and B are playing a game with a certain number of coins places on a table.
	Each player can pick atleast 'a' coins and atmost 'b' coins in his turn.
	If there are less than a coins left player has to pick all the coins left.

	Format 1: Person who picks the last coin wins	(Finder Winners)
	Format 2: Person who picks the last coin loses  (Keeper Loosers)

 	Example :-

	Format: 1 => Finder Winner

 	Players: A, B
 	n = 74 coins
 	a = 2 ,  b = 6

 	Min coins A should pick to win in Format 1.

	Idea is to reduce our game to nearest multiple of a+b in the 1st move

	74 -> 72 -> (72 - x) -> (72 - x - (8-x)) ..... -> 8 (B's turn)

	A always brings the number down to multiple of 8 after which always turn
	comes to B at last multiple  which is 8 itself turn is on B
	This ensures A's Win in format 1

	Format: 2 => Keeper Loosers

	If A reduces the number to something (a+b)k + n where n => [1,2,3...a]
	A will surely win

*/

bool isReducible(int n, int a, int b) {
	for (int i = a; i <= b; i++) {
		if ((n - i) % (a + b) == 0) {
			return true;
		}
	}
	return false;
}

bool kyaAJeetSakta(int n, int a, int b) {
	// can reduction to (a+b)k + n possible
	int nm = (n / (a + b)) * (a + b);
	for (int i = 1; i <= a; i++) {
		int no = nm + i;
		int diff = n - no;
		if (diff >= a and diff <= b) {
			return true;
		}
	}
	return false;
}

int main() {

	FIO;
	int a, b;
	int n;
	cout << "Format 1 :-" << endl;
	cin >> n >> a >> b;
	(isReducible(n, a, b)) ? cout << "A" : cout << "B";

	cout << "\n\nFormat 2 :- " << endl;
	(kyaAJeetSakta(n, a, b)) ? cout << "A" : cout << "B";
	return 0;
}
