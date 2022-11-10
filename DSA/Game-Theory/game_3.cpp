#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Game 3: Game of NIM

	Given a number of piles in which each pile contains some number of stones/coins.
	In each turn, a player can choose only one pile and remove any number of stones
	from that pile. Player who cannot move looses. Player picking last stone wins.

	Suppose 4 piles :-

	Pile 1: 1
	Pile 2: 4
	Pile 3: 3
	Pile 4: 2

	Example

	1. A,B,(1) 		=> winner A
	2. A,B,(1,1) 	=> winner B
	3. A,B,(1,2)	=> winner A (A will pick1 coin from pile with 2 coins)
	4. A,B,(2,2)	=> winner B
	5. A,B,(2,3)	=> winner A
	6. A,B,(3,3)	=> winner B

	States in this game :-

	1. Balanced State => B wins
	2. Unbalanced State => A wins

	Result : (Proof very lengthy)

	NIM Sum => XOR of all numbers for n piles

	if(NUM Sum == 0) => Balanced State
	else => Unbalanced State

	If a player is standing at winning state it can create a loosing state for
	its opponent by picking appropriate number.

*/

int main() {

	FIO;
	int n;
	cin >> n;
	int ans = 0;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		ans ^= t;
	}
	(ans == 0) ? cout << "B" : cout << "A";

	return 0;
}