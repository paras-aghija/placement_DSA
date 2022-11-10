#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// naive solution two pointer merge
// 


class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
       if(v2.size()<v1.size()) return findMedianSortedArrays(v2, v1);
       int n1 = v1.size();
       int n2 = v2.size();
       int l = 0, h = n1;
       int med = (n1+n2+1)/2
       while(l<=h){
            int c1 = l+(h-l)/2;
            int c2 = med-c1;
            int l1 = c1==0 ? INT_MIN : v1[c1-1];
            int l2 = c2==0 ? INT_MIN : v2[c2-1];
            int r1 = c1>=n1 ? INT_MAX : v1[c1];
            int r2 = c2>=n2 ? INT_MAX : v2[c2];

            if(l1<=r2 and l2<=r1){
                if((n1+n2)&1) return max(l1,l2);
                else return (max(l1,l2) + min(r1,r2))/2.0;
            }

            else if(l1>r2) h=c1-1;
            else l=c1+1;
       }
       return 0.0;
    }
};


int main(){
    
    FIO;
    

    return 0;
}