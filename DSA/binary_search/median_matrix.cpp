#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// search space [1.....1e9]
// nested binary search


// implementation of upperbound function
int smallerThanN(vector<int> &v, int n){
    int l=0, h=v.size()-1;
    while(l<=h){
        int mid = (l+h)/2;
        if(v[mid]<=n) l=mid+1;
        else h=mid-1;
    }
    return l;
}



int getMedian(vector<vector<int>> &v)
{
    // Write your code here.
    int l=0, h=1e9;
    int n = v.size();
    int m = v[0].size();

    while(l<=h){
        int mid = l + (h-l)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt += smallerThanN(v[i], mid);
        }

        if(cnt <= (n*m)/2) l=mid+1;
        else h=mid-1;
    }
    return l;
}

int main(){
    
    FIO;
    

    return 0;
}