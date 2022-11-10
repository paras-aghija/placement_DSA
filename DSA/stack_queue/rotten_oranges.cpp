#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

class Solution {
public:
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    int orangesRotting(vector<vector<int>>& v) {
        queue<pair<int,int>> q;
        int total = 0;
        for(int i=0;i<v.size();i++){
        	for(int j=0;j<v[0].size();j++){
        		if(v[i][j]!=0) total++;
        		if(v[i][j]==2) q.push({i,j});
        	}
        }

        int count = 0, days=0;
        while(!q.empty()){
        	int a = q.size();
        	count +=a;
        	while(a--){
        		auto e = q.front();
        		int x = e.first;
        		int y = e.second;
        		q.pop();
        		for(int i=0;i<4;i++){
        			int fx = x+dx[i], fy=y+dy[i];
        			if(fx<0 or fx>=v.size() or fy<0 or fy>=v[0].size() or v[fx][fy]!=1 ) continue;
        			v[fx][fy]=2;
        			q.push({fx, fy});
        		}
        	}
        	if(!q.empty()) days++;
        }
        if(total==count) return days;
        else return -1;
    }
};

int main(){
	
	FIO;
	

	return 0;
}