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
#define graph 				map<int, pair<int,vi>>
using namespace std;

graph g;

bool compare(int a, int b) {
	if (g[a].first == g[b].first) {
		return g[a].second.size() > g[b].second.size();
	}
	return g[a].first > g[b].first;
}

void printv(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int nodeCount(graph &g, int node) {
	if (g.find(node) == g.end()) {
		return g[node].first = 0;
	}
	for (auto child : g[node].second) {
		g[node].first += nodeCount(g, child) + 1;
	}
	sort(g[node].second.begin(), g[node].second.end(), compare);
	return g[node].first;
}

ll fun(graph &g, int node, int x) {
	if (g[node].first == 0) {
		return x;
	}
	ll ans = x;
	int i = 1;
	for (auto child : g[node].second) {
		ans += fun(g, child, x * i);
		ans %= mod;
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
		g[u].first = 0;
		g[u].second.pb(v);
	}
	nodeCount(g, 1);
	for (auto i : g) {
		cout << i.first << " : " << i.second.first << " -> ";
		printv(i.second.second);
	}
	cout << fun(g, 1, x) << endl;
	g.clear();
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