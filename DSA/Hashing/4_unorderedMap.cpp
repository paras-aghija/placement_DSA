#include<iostream>
#include<unordered_map>
using namespace std;

/*
UNORDERED MAP
unordered map is the c++ implementation of a hash table
We will be using separate chaining technique

insertion deletion and searching is done in constant time on avg in unordered map

*/


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map<string,int> um;
	um.insert(make_pair("Mango",100));
	um["Banana"] = 20;
	um["Apple"] = 120;
	um["Lichi"] = 60;
	um["Pineapple"] = 80;

	//here order is not maintained random display
	for(auto i : um)
		cout<<i.first<<" "<<i.second<<endl;

	return 0;
}