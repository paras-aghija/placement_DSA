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

// did not get accepted

/*
HOLI : Holiday Accommodation ICPC

INPUT :-

T
n : Number of cities
n number of lines
x y z : x and y are connected where dist b/w them is z

Connected Graph : All cities are connected to one another

OUTPUT :-

For each testcase print largest distance travelled by all the people

Approach :-

counting contribution of each edge
*/

class Graph {
	int V;
	list<pair<int, int>> *l;

public:
	Graph(int v) {
		this->V = v;
		l = new list<pair<int, int>>[V];
	}

	void addEdge(int u, int v, int cost) {
		l[u].push_back({v, cost});
		l[v].push_back({u, cost});
	}

	int dfsHelper(int node, bool *visited, int *count, ll &ans) {
		// mark node as visited
		visited[node] = true;
		count[node] = 1;

		for (auto nbr_pair : l[node]) {
			int nbr = nbr_pair.first;
			int wt = nbr_pair.second;
			if (!visited[nbr]) {
				count[node] += dfsHelper(nbr, visited, count, ans);
				int nx = count[nbr];
				int ny = V - nx;
				ans += 2 * min(nx, ny) * wt;
				// cout << nbr << " " << ans << endl;
			}
		}
		// just before leaving the node a return count of that particular node
		return count[node];
	}

	ll dfs() {
		bool visited[V];
		int count[V];
		for (int i = 0; i < V; i++) {
			visited[i] = false;
			count[i] = 0;
		}
		ll ans = 0;
		dfsHelper(0, visited, count, ans);
		return ans;
	}
};

int main() {

	FIO;
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		cout << "Case #" << c << ": ";
		int n, x, y, z;
		cin >> n;
		Graph g(n);
		for (int i = 1; i < n; i++) {
			cin >> x >> y >> z;
			g.addEdge(x - 1, y - 1, z);
		}
		cout << g.dfs() << endl;

	}


	return 0;
}