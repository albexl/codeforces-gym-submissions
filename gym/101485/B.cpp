#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second

#define int ll
int dp[205][205][205];

signed main()
{
	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, p;
	cin >> n >> p;
	vector<pair<int, int>> a(n);
	for (auto &i : a) cin >> i.F >> i.S;

	vector<int> g;
	vector<int> L, R;
	for (auto &i : a)
	{
		g.push_back(i.S - i.F);
		L.push_back(i.F);
		R.push_back(i.S);
	}

	sort(L.begin(), L.end());
	L.erase(unique(L.begin(), L.end()), L.end());

	sort(R.begin(), R.end());
	R.erase(unique(R.begin(), R.end()), R.end());

	memset(dp, 1<<7, sizeof dp);
	const int inf = dp[0][0][0];
	debug(inf)

	sort(a.begin(), a.end(), [](const pair<int, int> &x, const pair<int, int> &y){ return x.S < y.S; });

	for (int pos = 0; pos < L.size(); ++pos)
	{
		if (L[pos] >= R[0]) break;
		dp[0][pos][1] = max(dp[0][pos][1], R[0] - L[pos]);
	}

	for (int i = 0; i < n; ++i)
		for (int l = 0; l < L.size(); ++l)
			for (int k = 0; k <= p; ++k)
				if (dp[i][l][k] != inf)
				{
					if (a[i].F <= L[l])
					{
						dp[i+1][l][k] = max(dp[i+1][l][k], dp[i][l][k]);
					}

					int pos = lower_bound(L.begin(), L.end(), a[i].F) - L.begin();
					for (; pos < L.size(); ++pos)
					{
						if (L[pos] >= a[i].S) break;
						dp[i+1][pos][k+1] = max(dp[i+1][pos][k+1], dp[i][l][k] + a[i].S - L[pos]);
					}
				}

	sort(g.begin(), g.end(), greater<int>());

	int ans = inf;
	for (int i = 0; i < L.size(); ++i)
		for (int k = 1; k <= p; ++k)
		{
			int cost = dp[n][i][k];
			if (cost != inf)
			{
				for (int it = p - k, j = 0; it--; ++j)
					cost += g[j];
				ans = max(ans, cost);
			}
		}

	cout << ans << "\n";

	return 0;
}