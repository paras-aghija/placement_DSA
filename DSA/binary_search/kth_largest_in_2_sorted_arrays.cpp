#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


int ninjaAndLadoos(vector<int> &v1, vector<int> &v2, int m, int n, int k) {
    // Write your code here.,
    if(m>n) return ninjaAndLadoos(v2, v1, n, m, k);

    int l=max(0,k-n), h=min(k,m);
    while(l<=h){
        int c1 = (l+h)>>1;
        int c2 = k-c1;
   
        int l1 = c1==0 ? INT_MIN : v1[c1-1];
        int l2 = c2==0 ? INT_MIN : v2[c2-1];
        int r1 = c1>=m ? INT_MAX : v1[c1];
        int r2 = c2>=n ? INT_MAX : v2[c2];
        
        if(l1<=r2 and l2<=r1) return max(l1, l2);
        else if (l1>r2) h=c1-1;
        else l=c1+1;
    }
     return 0;    
}

int main(){
    
    FIO;
    

    return 0;
}