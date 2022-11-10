#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        for(int i=0;i<n;i++) s.push(i);
        
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(M[a][b] and !M[b][a]){
                s.push(b);
            }
            else if(M[b][a] and !M[a][b]){
                s.push(a);
            }
        }
        
        if(s.size()==0) return -1;
        
        int x = s.top();
        for(int i=0;i<n;i++){
            if(i==x) continue;
            if(M[x][i]) return -1;
            if(!M[i][x]) return -1;
        }
        return x;
        
    }
};

int main(){
    
    FIO;
    

    return 0;
}