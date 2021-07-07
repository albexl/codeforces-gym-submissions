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

	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 1, u, v; i < n; ++i)
	{
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> sz(n), heavy(n, -1), parent(n, -1);
	function<void(int, int)> dfs = [&](int u, int p)
	{
		sz[u] = 1;
		for (auto v : adj[u])
			if (v != p)
			{
				parent[v] = u;
				dfs(v, u);
				if (heavy[u] == -1 || sz[v] > sz[heavy[u]])
					heavy[u] = v;
				sz[u] += sz[v];
			}
	};

	dfs(0, -1);

	int j = 0;
	vector<pair<int, int>> ans(n);

	vector<bool> ok(n);
	function<void(int, int)> f = [&](int u, int i)
	{
		ok[u] = true;
		debug(u, i)
		ans[u] = { i, j };
		++j;

		vector<vector<int>> h;
		for (auto v : adj[u])
			if (v != parent[u] && !ok[v])
			{
				int x = v;
				h.push_back({ x });
				while ((x = heavy[x]) != -1)
					h.back().push_back(x);
				for (auto z : h.back()) ok[z] = true;
			}

		for (auto &k : h)
			for (auto v : k)
				f(v, i+1);
	};

	f(0, 0);
	for (auto i : ans)
	{
		swap(i.F, i.S);
		cout << i.F+1 << " " << i.S+1 << "\n";
	}

	return 0;
}