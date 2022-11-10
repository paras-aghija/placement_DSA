#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

/*
MAP STL
Map in stl is a container which helps in mapping key value pairs
Map internally uses a self balancing binary tree to maintain the mappings
maps is an inbuilt feature which can be used to implement a hash table
keys are ordered according to key values in a map(self balancing binary tree)

*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<string, int> m;

	//1.Insertion
	m.insert(make_pair("Mango",100));
	
	pair<string, int> p;
	p.first = "Apple";
	p.second = 120;
	m.insert(p);

	m["Banana"] = 20;

	//2.Search
	string fruit;
	cin>>fruit;

	auto it = m.find(fruit);
	//returns an iterator to fruit node
	//returns end iterator if not present
	if(it!=m.end())
		cout<<"Price of "<<fruit<<" is "<<m[fruit]<<endl;

	else
		cout<<"Fruit is not present"<<endl;

	//erase
	m.erase(fruit);

	//another way to find keys
	//it stores unique keys only once

	if(m.count(fruit) == 1) // returns 1 or 0
		cout<<fruit<<" : "<<m[fruit]<<endl;

	else
		cout<<"Could not find the fruit"<<endl;


	//Updating the price
	m["Apple"] += 22;
	cout<<"New price of Apple: "<<m["Apple"]<<endl;

	//iterate over all key value pairs
	m["Lichi"] = 60;
	m["Pineapple"] = 80;

	//keys are sorted lexographically
	for(auto it = m.begin();it!=m.end();it++)
		cout<<it->first<<" "<<it->second<<endl;

	//Using a for each loop
	cout<<endl;
	for(auto p : m)
		cout<<p.first<<" "<<p.second<<endl;
	return 0;
}