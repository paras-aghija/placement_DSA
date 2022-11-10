#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*
	Algo to find max flow in  a given network graph

	1. Flow cannot be greater than the max capacity of an edge
	2. for 2 vertex A<->B the amt of flow going in should be equal to flow going out
	   Excluding source and sink
	3. For any augumented Path(non 0 residual flow) : A->B->C->D max flow = Min edge wt
	4. Any path we are considering as augumented should have non zero backward edge
	   and a non full forward edge

	FORD FULKERSON ALGORITHM :-

	1. Setup our directed residual graph with edge capacity = original graph wts
	2. initialise max_flow = 0
	3. while there exist any augumented path from src to sink {
		* find the value f which is minimum edge wt along that augumented path
		* decrease the capacity of all the forward edges by f
		* increase the capacity of all the backward edges by f
		* increase the value of max_flow by f
	}
*/

int main() {

	FIO;


	return 0;
}