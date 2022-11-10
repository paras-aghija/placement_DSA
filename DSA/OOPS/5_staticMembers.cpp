#include<bits/stdc++.h>
using namespace std;

class Player
{

	static int count; // static variables are declared only once and shared across all objects

public:
	
	Player()
	{	count++;	}
	~Player()
	{	count--;	}

	static int getCount()
	{	return count;	}
	//static functions are not allowed to use non static data members as then it can be accessed
	//directly using the class name (also they can only call static functions within them )
	//normal functions also have acess to static data members
	//it is preferred to operate over static data members usig static functions
	//static functions do not have any this pointer
};

int Player::count = 0;
//static data member must be defined outside the class

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif
	Player p1,p2;
	// cout<<Player::count<<endl;// static variables can be used directly from the class name
	// {
	// 	Player p3;
	// 	cout<<Player::count<<endl;
	// }//p3 is declared therefore count is reduced
	// cout<<Player::count<<endl;
	cout<<Player::getCount()<<endl;// static variables can be used directly from the class name
	{
		Player p3;
		cout<<Player::getCount()<<endl;
	}//p3 is declared therefore count is reduced
	cout<<Player::getCount()<<endl;
	return 0;
}