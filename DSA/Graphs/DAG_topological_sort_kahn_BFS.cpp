#include<queue>

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    // Write your code here
     vector<int> in(n);
    vector<vector<int>> v(n);
    for(auto e : edges){
        in[e[1]]++;
        v[e[0]].push_back(e[1]);
    }
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(int nbr : v[node]){
            if(in[nbr]>0){
                in[nbr]--;
                if(in[nbr]==0) q.push(nbr);
            }
        }
    }
    return ans;
}