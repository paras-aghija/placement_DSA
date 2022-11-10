#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

#define INT_BITS 32

int maxSubarrayXOR(vector<int> set)
{
	int n = set.size();
    int index = 0;
    for (int i=INT_BITS-1; i>=0; i--)
    {
        int maxInd = index, maxEle = INT_MIN;
        for (int j=index; j<n; j++)
        {
             if ( (set[j]&(1<<i))!= 0 && set[j]>maxEle )
                maxEle = set[j], maxInd = j;
        }
        if (maxEle == INT_MIN)
           continue;
        swap(set[index], set[maxInd]);
        maxInd = index;
        for (int j=0; j<n; j++)
        {
            if ((j!=maxInd) && ((set[j] & (1<<i)) !=0))
                set[j] = set[j]^set[maxInd];
        }
        index++;
    }
    int res = 0;
    for (int i=0; i<n; i++)
        res ^= set[i];
    return res;
}

int mod = 1e9+7;

int nthCatalan(int k){
    vector<int> catalanNum(k,0);
    catalanNum[0]=catalanNum[1]=1;
    for(int i=2;i<=k;i++){
        for(int j=0;j<i;j++){
            catalanNum[i]+=catalanNum[j]*catalanNum[i-j-1];
            catalanNum[i]%=mod;
        }
    }
    return catalanNum[k];
}

int validParentheses(int N){
    int k=N/2;
    return nthCatalan(k);
}

int main(){
	
	FIO;
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	int x = maxSubarrayXOR(v);
	cout<< (validParentheses(2*x)*k)%mod;
	

	return 0;
}