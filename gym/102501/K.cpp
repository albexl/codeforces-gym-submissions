#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<int> point;
#define F first
#define S second

vector<int> dominators(const vector<vector<int>> &g, int r)
{
	int n = g.size();
	vector<int> ord, rank(n, n), prev(n, n), anc(n, n), idom(n, n), semi(n), low(n);
	vector<vector<int>> g_rev(n), dom(n);
	function<void(int)> dfs = [&](int u)
	{
		rank[u] = ord.size();
		ord.emplace_back(u);
		for (int v : g[u])
		{
			g_rev[v].emplace_back(u);
			if (rank[v] < n) continue;
			prev[v] = u;
			dfs(v);
		}
	};
	dfs(r);
	for (int i = 0; i < n; ++i) semi[i] = low[i] = i;
	function<int(int)> eval = [&](int v)
	{
		if (anc[v] < n && anc[anc[v]] < n)
		{
			int x = eval(anc[v]);
			if (rank[semi[low[v]]] > rank[semi[x]]) low[v] = x;
			anc[v] = anc[anc[v]];
		}
		return low[v];
	};
	for (int i = (int) ord.size() - 1; i >= 1; --i)
	{
		int w = ord[i];
		for (int v : g_rev[w])
		{
			int u = eval(v);
			if (rank[semi[w]] > rank[semi[u]]) semi[w] = semi[u];
		}
		dom[semi[w]].emplace_back(w);
		anc[w] = prev[w];
		for (int v : dom[prev[w]])
		{
			int u = eval(v);
			idom[v] = (rank[prev[w]] > rank[semi[u]] ? u : prev[w]);
		}
		dom[prev[w]].clear();
	}
	for (int i = 1; i < ord.size(); ++i)
	{
		int w = ord[i];
		if (idom[w] != semi[w]) idom[w] = idom[idom[w]];
	}
	for (int u = 0; u < n; ++u)
		if (idom[u] >= n) idom[u] = -1;
	return idom;
}

int main()
{
	#ifdef NeverBeRed
		freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<int>> adj(n), radj(n);
	for (int u, v; m--; )
	{
		cin >> u >> v;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}

	auto dom = dominators(radj, r);
	debug(dom);

	vector<vector<int>> g(n+1);
	for (int i = 0; i < n; ++i)
	{
		if (dom[i] == -1)
			dom[i] = n;
		g[dom[i]].push_back(i);
	}

	int id = 0;
	vector<int> dt(n+1), ft(n+1);
	function<void(int, int)> dfs = [&](int u, int p)
	{
		dt[u] = id++;
		for (auto v : g[u])
			if (v != p)
			{
				dfs(v, u);
			}
		ft[u] = id++;
	};
	dfs(n, -1);

	vector<int> ans;
	for (auto u : radj[r])
	{
		bool ok = true;
		for (auto v : adj[u])
		{
			debug(u, v, dt[u], ft[u], dt[v]);
			ok &= v == r || dom[v] == n || (dt[u] <= dt[v] && dt[v] <= ft[u]);
		}
		if (ok)
			ans.push_back(u);
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto &i : ans)
		cout << i << "\n";

	return 0;
}