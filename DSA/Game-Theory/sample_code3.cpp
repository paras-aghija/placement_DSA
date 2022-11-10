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

void solve() {
	ll n, m;
	cin >> n >> m;
	map<ll, ll> g;
	for (int i = 2; i <= n; i++) {
		g[m % i]++;
	}
	ll ans = n - 1;
	for (auto i : g) {
		ll t = i.second;
		ans += (t * (t - 1)) / 2;
	}
	cout << ans << endl;
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