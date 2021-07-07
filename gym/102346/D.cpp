#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second



int main()
{
	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> adj(n);
	for (int i = 1, x; i < n; ++i)
	{
		cin >> x;
		--x;
		adj[x].push_back(i);
	}

	vector<int> d(n), go(n, -1);
	function<void(int)> dfs = [&](int u)
	{
		for (auto v : adj[u])
		{
			dfs(v);
			if (d[v]+1 > d[u])
			{
				d[u] = d[v]+1;
				go[u] = v;
			}
		}
	};

	dfs(0);

	priority_queue<pair<int, int>> pq;
	pq.push({ d[0], 0 });

	int ans = 0;
	while (k-- && !pq.empty())
	{
		int u = pq.top().S;
		pq.pop();
		ans += d[u]+1;

		do
		{
			for (auto v : adj[u])
				if (v != go[u])
					pq.push({ d[v], v });

			u = go[u];
		} while (u != -1);
	}

	cout << ans << "\n";

	return 0;
}