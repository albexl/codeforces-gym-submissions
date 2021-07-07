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

int sz[105];
int dp[105][105];

int main()
{
	#ifdef DGC
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> c(n);
	for (auto &i : c) cin >> i;

	vector<vector<int>> adj(n);
	for (int i = 1, u, v; i < n; ++i)
	{
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		swap(u, v);
		adj[u].push_back(v);
	}

	int dist;
	function<void(int, int)> dfs = [&](int u, int p)
	{
		sz[u] = c[u];
		dp[u][0] = 0;
		if (sz[u]) dp[u][1] = 0;

		for (auto v : adj[u])
			if (v != p)
			{
				dfs(v, u);

				for (int i = sz[u]; i >= 0; --i)
					for (int j = 1; j <= sz[v]; ++j)
						if (dp[u][i] + dp[v][j] + 1 <= dist)
							dp[u][i+j] = min(dp[u][i+j], max(dp[u][i], dp[v][j] + 1));

				sz[u] += sz[v];
			}
	};

	auto go = [&](int d)
	{
		dist = d;
		memset(sz, 0, sizeof sz);
		memset(dp, 63, sizeof dp);
		const int inf = dp[0][0];
		dfs(0, -1);
		for (int u = 0; u < n; ++u)
			if (dp[u][m] != inf)
				return true;
		return false;
	};

	int l = 0, r = n-1;
	while (l < r)
	{
		int md = (l+r) >> 1;
		if (go(md))
			r = md;
		else
			l = md+1;
	}

	cout << l << "\n";

	return 0;
}