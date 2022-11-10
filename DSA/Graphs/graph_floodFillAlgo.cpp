#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
/*
	Color fill type functionality
	This algorithm is generally performed on implicit graphs

	starting from a particular cell we can calll dfs on the neighbouring cells
	neighbours can be 4 : up down left right
	or 8 if diagonals are included also

	INPUT

15 30
..............................
............#####.............
............#...#.............
.....########...#######.......
....###....######.....###.....
...##...................##....
..##.....................##...
..##.....................##...
...##...................##....
....##.................##.....
.....##...............##......
......##.............##.......
.......##...........##........
........#############.........
..............................

*/

// L,D,R,U
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

// ch is the character to be replaced
// color is the character to be added
void floodFill(char mat[][50], int R, int C, int i, int j, char ch, char color) {
	// Base Case (Matrix Bounds)
	if (i<0 or j<0 or i >= R or j >= C) {
		return;
	}
	// Figure Boundary Condition
	if (mat[i][j] != ch) {
		return;
	}

	// Recursive Call
	mat[i][j] = color;
	for (int k = 0; k < 4; k++) {
		floodFill(mat, R, C, i + dx[k], j + dy[k], ch, color);
	}
}
int main() {

	FIO;
	int R, C;
	cin >> R >> C;
	char input[R][50];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> input[i][j];
		}
	}

	floodFill(input, R, C, 8, 13, '.', 'r');


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << input[i][j];
		}
		cout << endl;
	}

	cout << endl;

	floodFill(input, R, C, 3, 15, '.', 'o');


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << input[i][j];
		}
		cout << endl;
	}

	cout << endl;

	floodFill(input, R, C, 1, 1, '.', 'b');


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << input[i][j];
		}
		cout << endl;
	}
	return 0;
}