#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

	Determining that problem is DP based or Greedy based is vey imp

	In greedy algorithm :-

	- Make a choice that looks best at the particular moment
	- Choeoe a local optimum at each step and you will end up at global optimum


	Eg L:-

	Currency change problem :-

	Denominations (Indian) : [1,2,5,10,20,50,100,200,1000,2000]

	For Rs 39 = 30 -> 10 -> 5 -> 2 -> 2
	We are choosing local optimum at each level to reach the ans
	Greedy way of thinking

	In DP way we will check all possible paths and will return path
	which gives ans in min steps

	But...

	Denominations (Let) : [1.7,10]

	Rs 15 : (Greedy) 10 -> 1 -> 1 -> 1 -> 1 -> 1

	But ans : 7 -> 7 -> 1 (DP will give this ans as it explores all paths)

	Therefore greedy do not work for all problems
*/

int main() {

	FIO;


	return 0;
}