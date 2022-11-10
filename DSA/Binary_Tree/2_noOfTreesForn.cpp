#include<bits/stdc++.h>
using namespace std;

/*
To find no. of binary trees which can be formed for given no. of nodes n

Case 1 : when nodes are unlabeled

	n = 3 no. of trees possible = 5
	n = 4 no. of trees possible = 14

	genral formula CATALAN NUMBER

	T(n) = (2n C n) / (n+1)

	Therfore for n = 5 no. of trees possible = 42

	NOTE : 

	for n = 3 no. of trees with max height(2) = 4 = 2^2
	for n = 4 no. of trees with max height(3) = 8 = 2^3

	General formula : no. of trees with max height = 2 ^ (n-1)

	CATALAN NUMBERS

	from n : 0->5 =  1 1 2 5 14 42

	T(6) = 1*42 + 1*14 + 2*5 + 5*2 + 14*1 + 42*1 = 132

	T(n) = sumation i : 1->n ( T(i-1) * T(n-1) ) 
	recursive formula of catalan numbers

Case 2 : when the nodes are labeled

	for n = 3 no. of trees possible = 5 * fact(3)

	General formula = [ (2n C n) / (n + 1) ] * fact(n)
						SHAPES					FILLING
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif
	return 0;
}