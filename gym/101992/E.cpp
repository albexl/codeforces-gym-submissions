#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715;
#endif
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second

const int mod = 1e9+7;
int dp[205][205][205];

void add(int &x, int y)
{
	x += y;
	if (x >= mod)
		x -= mod;
}

int solve(int n, int k)
{
	memset(dp, 0, sizeof dp);
	dp[0][1][0] = 1;
	dp[0][1][1] = mod-1;
	for (int i = 0; i < n; ++i)
		for (int j = 1; j <= k; ++j)
			for (int g = 0; g <= n; ++g)
			{
				if (g) add(dp[i][j][g], dp[i][j][g-1]);

				if (j < k && g > 0)
				{
					add(dp[i+1][j+1][0], dp[i][j][g]);
					add(dp[i+1][j+1][g], mod-dp[i][j][g]);
				}

				int l = n-i - g;
				if (l > 0)
				{
					add(dp[i+1][1][g], dp[i][j][g]);
					add(dp[i+1][1][g+l], mod-dp[i][j][g]);
				}
			}
	int ans = 0;
	for (int j = 1; j <= k; ++j)
		add(ans, dp[n][j][0]);
	return ans;
}

int main()
{
	#ifdef DGC
		//freopen("b.out", "w", stdout);
	#endif

	freopen("permutations.in", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int ans = solve(n, k);
		add(ans, mod-solve(n, k-1));
		cout << ans << "\n";
	}

	return 0;
}