#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m;
string A, B;
int dp[3005][3005];

inline int LCS()
{
	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	for (int j = 0; j <= m; j++) dp[0][j] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (A[i - 1] == B[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	return dp[n][m];
}

inline string getLCS()
{
	string ret;
	stack<char> S;
	int ii = n, jj = m;
	while (ii != 0 && jj != 0)
	{
		if (A[ii - 1] == B[jj - 1])
		{
			S.push(A[ii - 1]);
			ii--; jj--;
		}
		else if (dp[ii - 1][jj] > dp[ii][jj - 1]) ii--;
		else jj--;
	}
	while (!S.empty())
	{
		ret += S.top();
		S.pop();
	}
	return ret;
}

int main() {

	FIO;
	cin >> A >> B;
	n = A.length();
	m = B.length();
	LCS();
	cout << getLCS();

	return 0;
}