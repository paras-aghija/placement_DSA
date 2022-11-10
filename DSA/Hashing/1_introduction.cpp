//HASHING
//HASH TABLE
#include<bits/stdc++.h>
using namespace std;

/*
HASH TABLE

It must have following functionalities

	-insertion
	-deletion
	-search (avg case is constant time)
	(order of accessing data is random)


HASH FUNCTION

	Example :-
	Hash["string key"] = integer
	
	General
	Hash[Data1] = Data2
	where Data1 and Data2 are of any datatype

So basically when accessing elements in a hash table
when we ask for the value at Data1 position
hashtable passes data1 to a function and
hash function returns an index or a location
where boot Data1 and Data2 are stored in the memory

it might happen that hash function generates same value
for two different Data1 therefore for that we handle collisions separately

To avoid collisions we should have a good hash functions
good hash function must reduced chance of collision
should be fast (Access)

Example :-

Assume keys to be integers
hash(key) = key % table size

HASHING STRINGS

We can use first 3 characters of the string for hashing
example :-

	abc = ascii(a) + ascii(b) + ascii(c)
	but this hash function is too prone to collisions

	instead we use h = a + b*27 + c*(27^2)
	hash value = h % table size
	this is comparitively less prone to collisions
	but some words with same prefixes might collide
	
	we can also use above series for all characters in the string
	rathar than just doing it for 3 characters
	but if word is too large then it mught go beyond the int max
	but it will reduce collisions to neglegible

COLLISION HANDLING

	1.Open hashing - Separate Chaining

	2.Closed hashing

	3.Double hashing

SEPARATE CHAINING

	-Implemented using linked list
	implemented in next file...

NOTE : To reduce collisions we can increase table size to number of elements

Load factor = currenct_size / total_size of table
we can set a threshold on load factor

if load factor becomes > 0.75
increase the total_size by creating a new table
and rehashing old values to the new table
incresed size must be a prime number near to atleast 2 times the old size

reashing also involves change of hash values for each Data1
as each hash value is determined by table_size which in turn is changed


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