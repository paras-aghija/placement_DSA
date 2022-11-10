// magneto_19
#include<bits/stdc++.h>
#define FIO 				ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll 					long long
#define vl 					vector<ll>
#define vi 					vector<int>
#define vvi 				vector<vector<int>>
#define pb 					push_back
#define mp 					make_pair
#define pii 				pair<int,int>
#define pll         		pair<ll,ll>
#define pci         		pair<char,int>
#define lb          		lower_bound
#define ub          		upper_bound
#define mi 					map<int,int>
#define mk(arr,n,type) 		type *arr = new type[n]
#define mod 				1000000007
#define w(x) 				int x; cin>>x; while(x--)
#define pi 					3.14159265358979323846
#define gcd(a,b) 			__gcd((a),(b))
#define lcm(a,b) 			((a)*(b))/gcd((a),(b))
#define print(x) 			for(auto i:(x))cout<<i<" "; cout<<endl;
#define all(x)      		x.begin(),x.end()
#define rall(x)     		x.rbegin(),x.rend()
#define setbits(x)			__builtin_popcountll(x)
#define tzbits(x)			__builtin_clzll(x)
#define lzbits(x)			__builtin_ctzll(x)
#define ps(x,y)				fixed<<setprecision(y)<<x
using namespace std;
map<int, pair<int, vi>> graph;


void printv(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

bool compare(int a, int b) {
	return graph[a].first > graph[b].first;
}

int height(map<int, pair<int, vi>> &graph, int node) {
	if (graph.find(node) == graph.end()) {
		return graph[node].first = 0;
	}
	for (auto p : graph[node].second) {
		graph[node].first += (height(graph, p)) + 1 ;
	}
	sort(graph[node].second.begin(), graph[node].second.end(), compare);
	return graph[node].first;
}



ll fun(map<int, pair<int, vi>> &graph, int node, int x) {
	if (graph[node].first == 0) {
		return x;
	}
	ll ans = x;
	int i = 1;
	for (auto child : graph[node].second) {
		ans += fun(graph, child, x * i);
		i++;
	}
	return ans;
}

void solve() {
	ll n, x;
	cin >> n >> x;
	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		graph[u].first = 0;
		graph[u].second.pb(v);
	}
	height(graph, 1);

	for (auto i : graph) {
		cout << i.first << " : ";
		int height = i.second.first;
		cout << height << " -> ";
		printv(i.second.second);
	}
	cout << fun(graph, 1, x) << endl;
	graph.clear();
}

int main() {

	FIO;
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}