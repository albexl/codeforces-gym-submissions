#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<pii>> graph;

const ll maxn = 100 + 5, mod = 1e9 + 7;

int A[maxn], C[maxn];
ll dp[maxn][maxn][maxn];

ll solve(int b, int e, int p)
{
	if(b > e) return 1;
	if(dp[b][e][p] != -1) return dp[b][e][p];

	if(b == e)
		dp[b][e][p] = (A[b] == C[p]) || (C[p] == -1);
	else
	{
		dp[b][e][p] = 0;
		for(int i = b; i <= e; ++i)
			if(C[p] == -1 || A[i] == C[p])
			{
				ll x = solve(b, i - 1, p - (e - i + 1));
				ll y = solve(i + 1, e, p - 1);
				dp[b][e][p] = (dp[b][e][p] + x * y) % mod;
			}
	}

	return dp[b][e][p];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> A[i];
	for(int i = 0; i < n; ++i)
		cin >> C[i];

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < n; ++k)
				dp[i][j][k] = -1;

	cout << solve(0, n - 1, n - 1) << endl;

	return 0;
}