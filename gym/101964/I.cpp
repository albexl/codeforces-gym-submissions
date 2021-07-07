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

ll dp[105][105][105];

int main()
{
	#ifdef DGC
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> g(n, vector<bool>(n));
	for (int i = 0, u, v; i < m; ++i)
	{
		cin >> u >> v;
		--u, --v;
		if (v < u) swap(u, v);
		g[u][v] = true; // u > v
		debug(u, " > ", v)
	}

	vector<int> deg(n);
	vector<vector<bool>> adj(n, vector<bool>(n));
	for (int u = 0; u < n; ++u)
		for (int v = u+1; v < n; ++v)
		{
			if (g[u][v])
			{
				adj[u][v] = true;
				debug(u, " >? ", v)
				++deg[v];
			}
			else
			{
				adj[v][u] = true;
				debug(v, " >? ", u)
				++deg[u];
			}
		}

	vector<int> ord;
	for (int i = 0; i < n; ++i)
		if (deg[i] == 0)
			ord.push_back(i);

	for (int i = 0; i < ord.size(); ++i)
	{
		int u = ord[i];
		for (int v = 0; v < n; ++v)
			if (adj[u][v] && !--deg[v])
				ord.push_back(v);
	}

	assert(ord.size() == n);

	reverse(ord.begin(), ord.end());
	debug(ord)

	vector<int> p(n);
	for (int i = 0; i < n; ++i)
		p[ord[i]] = i+1;

	debug(p)

	dp[0][0][n+1] = 1;

	for (int i = 0; i < n; ++i)
		for (int mx = 0; mx <= n; ++mx)
			for (int mn = 0; mn <= n+1; ++mn)
			{
				if (p[i] > mx)
				{
					dp[i+1][p[i]][(p[i] < mn) ? (n+1) : mn] += dp[i][mx][mn];
				}
				if (p[i] < mx)
				{
					dp[i+1][mx][mn] += dp[i][mx][mn];
				}
				else
				{
					dp[i+1][mx][min(mn, p[i])] += dp[i][mx][mn];
				}
			}

	ll ans = 0;
	for (int mx = 0; mx <= n; ++mx)
		ans += dp[n][mx][n+1];

	cout << ans << "\n";

	return 0;
}