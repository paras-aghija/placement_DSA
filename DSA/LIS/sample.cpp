#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


bool compare(vector<int> &a, vector<int> &b){
	return (a[0]!=b[0]) ? a[0]<b[0] : a[1]>b[1];
}

vector<vector<int>> solve(int N, vector<vector<int>> points){
	sort(points.begin(), points.end(), compare);
	return points;
}


int escape_from_grid(vector<vector<int>> v){
	int n = v.size(), m = v[0].size(), x, y;
	vector<int> dx = {1,-1,0,0};
	vector<int> dy = {0,0,1,-1};
	queue<pair<int,int>> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>v[i][j];
			if(v[i][j]==2) q.push({i,j});
		}
	}
	int ans = 0;
	while(!q.empty()){
		int s = q.size();
		for(int i=0;i<s;i++){
			int x = q.front().first;
			int y = q.front().second;
			if(x==0 or y==0 or x==n-1 or y==m-1) return ans;
			q.pop();
			for(int i=0;i<4;i++){
				int xx = x + dx[i];
				int yy = y + dy[i];
				if(xx>=0 and yy>=0 and xx<=n-1 and yy<=m-1 and v[xx][yy]==0) q.push({xx,yy});
			}
		}
		ans++;
	}
	return -1;
}

int main(){
	
	FIO;
	vector<int> dx = {1,-1,0,0};
	vector<int> dy = {0,0,1,-1};
	int n, m;
	cin>>n>>m;
	int x, y;
	vector<vector<int>> v(n, vector<int> (m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>v[i][j];
		}
	}
	cout<<escape_from_grid(v);

	return 0;
}