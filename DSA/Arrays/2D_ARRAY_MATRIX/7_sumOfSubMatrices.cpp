#include<bits/stdc++.h>
using namespace std;
#define N 10

/*
Problem Statement
To find sum of all submatrices of a given Matrix
in chich all the elements are 1 

1 1
1 1

4 submatrices (1 x 1) -> 1 + 1 + 1 + 1 = 4
2 submatrices (1 x 2) -> 2 + 2 = 4
2 submatrices (2 x 1) -> 2 + 2 = 4
1 submatrix	  (2 x 2) -> 4

a p x q matrix will give a contribution of (p*q)
n matrices of p x q will contribute n*(p*q)
sum of all sumatrices -> 16

APPROACH 1 (BRUTE FORCE)
A submatrix can be defined as a rectangle
all possible rectangles that can be formed in the matrix
will represent a submatrix
we can get to know a rectangle by just knowing its top left and bottom right coordinate
form otope left and bottom right coordinate we can find
its length breadth position area and everything

if we can define all pssible pairs of top left and bottom right
we can easily extract out all possible submatrices

for top left
i can go from 0 to r-1
j can go from 0 to c-1

for i,j as top left
bottom right possiblities are
x starting from i to r-1
y starting from j to c-1 

Time Complexity of his approach is O(n^4)
Space Complexity = O(1)


APPROACH 2
Every element in matrix will be a part of more than 1 submatrices
and in each submatrix the element will be contributing for the sum
instead of calculating all the possible submatrics we can think reverse
we can calculate contribution by each element in the whole sum
if a cell is a part of say 4 sub matrices
then its contribution to overall sum will be a[i][j] * 4

consider a cell i,j
then cells above and to te right of i-1,j+1 can never be top left and bottom right for i,j
in region from 0,0 to i,j all cells are relevant to be top left for i,j
not onl the choice of top left matter but choice of bottom right also matters
for i,j to be inclucded in the submatrix
region from i,j to r-1,c-1 are most relavant to be bottom right for i,j to be included in submatrix

1 1 1 1 0 0
1 1 1 1 0 0
1 1 1 x 2 2
0 0 0 2 2 2

x -> i,j being considered included in both region 1 and 2
1 -> region in which we can choose top left
2 -> region in which we can choose bottom right

if we choose top left and bottom right using above conditions
then we will get all the submatrices which will have i,j(x cell) inside it
now problem becomes simple permutation nd combination problem

suppose there are p no. of cells in region 1
and q number of cells in region 2
to define a submatrc we need a pair of top left and bottom right
no, of pairs we can make from region 1 and region 2 :-

	Total submatrices possible (containing i,j)= x * y
	x = (i+1)*(j+1)
	y = (r-i)*(c-j)

now we apply this to above formula to compute the final ans
Time Complexity of this approach is O(n^2)
Space Complexity O(1)
*/

void approach1(int r, int c)
{
	int l,b,contribution;
	int sum = 0;
	for(int li=0;li<r;li++)
	{
		for(int lj=0;lj<c;lj++)
		{
			for(int bi=li;bi<r;bi++)
			{
				for(int bj=lj;bj<c;bj++)
				{
					cout<<li<<" "<<lj<<" "<<bi<<" "<<bj<<endl;
					//we will get all possible pairs of top left and top right
					//top left = (li,lj)
					//bottom right = (bi,bj)
					// for(int i=li;i<=bi;i++)
					// {
					// 	for(int j=lj;j<=bj;j++)
					// 		sum++;
					// }

					//only if all elements are 1 then
					l = bi - li + 1;
					b = bj - lj + 1;
					contribution = l*b;
					sum += contribution;

					//if all elements are not 1 we make a prefix suum matrix first
					//and then subtract bottom left val with top right to get the contribution of a given subarray
					//explanation given below
					//if we had already made prefix sum array pre
					//prefix sum row wise and column wise separately to obtain prefix sum matrix
					// contribution = pre[bi][bj] - pre[li-1][bj] - pre[bi][lj-1] + pre[li-1][lj-1];
					// sum += contribution;

				}
			}
		}
	}
	cout<<sum;	
	/*
	Prefix sum matrix

	a b c
	d e f
	g h i

	a a+b a+b+c
	d d+e d+e+f
	g g+h g+h+i

	a 		a+b 		  a+b+c
	a+d 	a+b+d+e 	  a+b+c+d+e+f
	a+d+g   a+b+d+e+g+h   a+b+c+d+e+f+g+h+i

	above matrix is a prefix sum matrix

	top left = 1,1
	bottom right = 2,2
	contribution = a+b+c+d+e+f+g+h+i - a+b+d+e 
	contribution = c + f + g + h + i
	not giving the correct answer
	draw diagram and analyze

	if i,j be top left
	and x,y be the bottom left

	sum1 = 0,0 -> i-1,y
	sum2 = 0,0 -> x,j-1
	sum3 = 0,0 -> i-1,j-1
	sum4 = 0,0 -> x,y

	contribution for i,j -> x,y
	contribution = sum4 - sum1 - sum2 + sum3
	this is the corect ans that we will get

	applyting formula in character prefix sum matrix

	top left = 1,1 (i,j)
	bottom right = 2,2 (x,y)

	sum1 = a+b+c
	sum2 = a+d+g
	sum3 = a
	sum4 = a+b+c+d+e+f+g+h+i

	contribution = e+f+h+i
	this is the correct contribution for given top left and bottom right



	*/
}

void approach2(int r, int c)
{
	int sum=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			sum += 1*((i+1)*(j+1))*((r-i)*(c-j));
			//1 is the value of the cell
			//and following is no. of matrices the cell is part of
		}
	}
	cout<<sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif

	int r,c;
	cin>>r>>c;
	//inputing matrix is not reqd as all elements are 1
	// int a[N][N];
	// for(int i=0;i<r;i++)
	// {
	// 	for(int j=0;j<c;j++)
	// 		cin>>a[i][j];
	// }
	approach2(r,c);

	return 0;
}