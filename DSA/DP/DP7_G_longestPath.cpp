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

void printv(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int sublen(vi v) {
	int ans = 0, la = 0;
	bool f = false;
	for (auto i : v) {
		if (i == 1) {
			if (f == false) {
				f = true;
				la = 1;
			}
			else {
				la++;
			}
		}
		else {
			f = false;
			ans = max(ans, la);
		}
	}
	return ans;
}

int fun(vi &v, int k, vi &vans) {

	if (k == 0) {
		return sublen(v);
	}
	int ans = 0;
	for (auto &i : v) {
		if (i == 0) {
			i = 1;
			int t = fun(v, k - 1, vans);
			cout << ans << " : " << t << "  ";
			if (ans < t) {
				ans = t;
				vans = v;
				printv(v);
			}
			i = 0;
		}
	}
	return ans;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vi v(n), vans;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << fun(v, k, vans) << endl;
	printv(vans);

}

int main() {

	FIO;
	solve();

	return 0;
}