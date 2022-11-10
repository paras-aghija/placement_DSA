#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#define ll long long
/*

Matrix Multiplication

	A => r1,c1
	B => r2,c2

	A*B = C  Only if (c1 == r2)

	Cost Of multiplication :-

	Assume 1 multiplication operation : O(1)

	To obtain one element in matrix C : O(c1) or O(r2)

	No. of elements in matrix C : r1 * c2

	Total cost to multiply 2 matrics : O(r1*c1*c2)

Matrix Chain Multiplication


	A => r1,c1
	B => r2,c2
	......
	......

	A * B * C * D * E * F * G = Z

	Cost to compute Z may vary on the order in which we multiply

	Eg :-

	Matrices   :  A    B    C    D
	Dimensions : 4,2  2,3  3,1  1,3 (Only 5 dimensions required)


	((AB)C)D : (4*2*3) + (4*3*1) + (4*1*3) = 48

	(A(BC))D : (2*3*1) + (4*2*1) + (4*1*3) = 26


We need to minimise the cost of multiplication

	We make a 2d matrix of n x n where n is the number of matrices we have
	Suppose 1 based indexing

	element at r,c in this matrix represents
	minimum cost of multiplying matrices from Ar -> Ac

	For ABC
	we can have two cases

	[(AB)C] and [A(BC)]
	For dp[1][3] => (dp[1][1],dp[2][3]) and (dp[1][2], dp[3][3])

	Recurence Relation

	dp[x][y] = min {

		dp[x][k] + dp[k+1][y] + (ar[x]*ar[k+1]*ar[y+1])
		let some ar contain the dimensions
		for all k belonging to [x,y-1]

	}

	Example :-

	dimensions :  ar[] = [4,2,3,1,3]

	dp = [
		[ 0 , 24, 14, 26],
		[   , 0 , 6 , 12],
		[   ,   , 0 , 9 ],
		[   ,   ,   , 0 ]
	]

	dp[1][2] = min{
		k:1 => dp[1][1] + dp[2][2] + ar[1]*ar[2]*ar[3] = 24
	} = 24

	dp[2][3] = min{
		k:2 => dp[2][2] + dp[3][3] + ar[2]*ar[3]*ar[4] = 6
	} = 6

	dp[3][4] = min{
		k:3 => dp[3][3] + dp[4][4] + ar[3]*ar[4]*ar[5] = 9
	} = 9

	dp[1][3] = min {
		k:1 => dp[1][1] + dp[2][3] + ar[1]*ar[2]*ar[4] = 0 + 6 + 8 = 14
		k:2 => ap[1][2] + dp[3][3] + ar[1]*ar[3]*ar[4] = 24 + 0 + 12 = 36
	} = 14

	dp[2][4] = min {
		k:2 => dp[2][2] + dp[3][4] + ar[2]*ar[3]*ar[5] = 0 + 9 + 18 = 27
		k:3 => ap[2][3] + dp[4][4] + ar[2]*ar[4]*ar[5] = 6 + 0 + 6 = 12
	} = 12

	dp[1][4] = min {
		k:1 => dp[1][1] + dp[2][4] + ar[1]*ar[2]*ar[5] = 0 + 12 + 24 = 36
		k:2 => dp[1][2] + dp[3][4] + ar[1]*ar[3]*ar[5] = 24 + 9 + 36 = 69
		k:3 => dp[1][3] + dp[4][4] + ar[1]*ar[4]*ar[5] = 14 + 0 + 12 = 26
	} = 26


	ans => dp[1][4] = 26

Time Complexity : O(n^3)
Space Complexity : O(n^2)


*/

void solve() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 0; i <= n; i++) {
		cin >> v[i];
	}
	int dp[200][200];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n; i++) {
		int r = 0, c = i;
		while (c < n) {
			int val = INT_MAX;
			for (int pivot = r; pivot < c; pivot++) {
				val = min(val, dp[r][pivot] + dp[pivot + 1][c] + (v[r] * v[pivot + 1] * v[c + 1]));
			}
			dp[r][c] = val;
			r++;
			c++;
		}
	}
	cout << dp[0][n - 1];
}

int main() {

	FIO;
	solve();

	return 0;
}