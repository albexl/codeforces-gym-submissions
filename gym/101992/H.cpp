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



int main()
{
	#ifdef DGC
		//freopen("b.out", "w", stdout);
	#endif

	freopen("path.in", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m, source, len, kth;
		cin >> n >> m >> source >> len >> kth;

		vector<vector<pair<int, int>>> adj(n+1);
		for (int u, v, w, i = 0; i < m; ++i)
		{
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			swap(u, v);
			adj[u].push_back({v, w});
		}

		vector<int> d(n+1, 1<<30);
		d[source] = 0;
		queue<int> q;
		q.push(source);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (auto v : adj[u])
				if (d[u] + 1 < d[v.F])
				{
					d[v.F] = d[u] + 1;
					q.push(v.F);
				}
		}

		int ans = -1;
		for (int u = 1; u <= n; ++u)
			if (d[u] < kth)
				for (auto v : adj[u])
					ans = max(ans, v.S);

		cout << ans << "\n";
	}

	return 0;
}