#include<bits/stdc++.h>
using namespace std;

/*
PIYUSH AND MAGICAL PARK
Problem Statement
You are given a 2D grid of n rows and m columns
2d grid is a magical park
in order to get out of the park
piyush needs atleast k amount of strength to safely reach home
to find if piyush can escape the path or not 
initial strength of s is given to piyush
some special characters denote obstacles
. -> strenght reduces by 2
# -> blocked
* -> strength gain +5
piyush can only travel left to right row wise 
if row is blocked piyush moves to the start of the next line
without loosing any strength
for move strength of 1 is used
for every move his strength should be greater than k
else piyush will get lost
piyush can shift from last of one row to start of next
without loosing any strength
his escape is successful if he is able to return home with atleast k strength

Example
grid size = 4 x 4
k = threshold strength = 5
S = initial strength = 20

. . * .
. # . .
* * . .
. # * *

output
yes
13

-1 -> 20
00 -> 18
01 -> 17(for movement) -> 15 for . encounter
02 -> 14 -> 19
03 -> 18 -> 16
next row withoud strength reduction

10 -> 14
11 -> 13 -> # blocked next row

20 -> 13 -> 18
21 -> 17 -> 22
22 -> 21 -> 19
23 -> 18 -> 16
next row

30 -> 16 -> 14
21 -> 13 -> # -> blocked
next row piyush comes out of the park

at every point strength was > 5
therefor yes and final strength is 13
ADHOC PROBLEM
*/

void magicalPark(char a[][100], int m, int n, int k, int s)
{
	//piyush can get out of the park
	bool success = true;

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			char ch = a[i][j];

			//check
			if(s<k)
			{
				success = false;
				break;
			}
			if(ch=='*')
				s+=5;

			else if(ch=='.')
				s-=2;

			//handles # case
			else
				break;

			if(j!=n-1)
				s--;
		}
	}

	if(success)
		cout<<"yes"<<endl<<s;

	else
		cout<<"no";
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

	int m,n,k,s;
	cin>>m>>n>>k>>s;
	char park[100][100];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cin>>park[i][j];
	}

	magicalPark(park,m,n,k,s);
	return 0;
}