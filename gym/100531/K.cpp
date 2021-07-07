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

inline void add(int &x, int y)
{
	x += y;
	if (x >= mod)
		x -= mod;
}

int main()
{
	//#ifdef DGC
		freopen("kebab.in", "r", stdin);
		freopen("kebab.out", "w", stdout);
	//#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, t;
	cin >> n >> t;

	vector<int> who(1000 * 255 + 5);
	vector<int> m(n);

	int p = 1;
	for (int i = 0, q; i < n; ++i)
	{
		cin >> q >> m[i];
		m[i] = q - m[i];
		for (int j = 0; j < q; ++j)
			who[p+j] = i;
		p += q;
	}

	int ans = 0;
	vector<vector<int>> dp(p + 2, vector<int>(255));
	dp[1][0] = 1;

	--p;
	for (int i = 1; i <= p; ++i)
		for (int j = 0; j <= 250; ++j)
		{
			// not dream
			if (i+1 <= p)
				add(dp[i+1][(who[i+1]==who[i]) ? j : 0], dp[i][j]);
			else
				add(ans, dp[i][j]);

			// dream
			if (j+1 <= m[who[i]])
			{
				if (i+t+1 <= p)
					add(dp[i+t+1][(who[i+t+1]==who[i]) ? (j+1) : 0], dp[i][j]);
				else
					add(ans, dp[i][j]);
			}
		}

	cout << ans << '\n';

	return 0;
}