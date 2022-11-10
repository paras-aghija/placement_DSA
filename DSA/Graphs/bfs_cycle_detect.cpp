#include<queue>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> v(n+1);
    for(auto e : edges){
        v[e[0]].push_back(e[1]);
        v[e[1]].push_back(e[0]);
    }
    vector<int> vis(n+1, 0);
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                vis[node]=1;
                q.pop();
                int cnt=0;
                for(int nbr : v[node]){
                    if(!vis[nbr]) q.push(nbr);
                    else cnt++;
                }
                if(cnt>1) {
                    return "Yes";
                }
            }
        }
    }    
    return "No";
}
