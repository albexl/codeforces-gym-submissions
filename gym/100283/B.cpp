#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second



int main()
{
	//#ifdef DGC
		freopen("road.in", "r", stdin);
		//freopen("b.out", "w", stdout);
	//#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int test;
	cin >> test;
	for (int t = 0; t < test; ++t)
	{
		int n, m;
		cin >> n >> m;

		struct edge { int u, v, w; };
		vector<edge> e(m);
		for (auto &i : e)
			cin >> i.u >> i.v >> i.w, --i.u, --i.v;

		sort(e.begin(), e.end(), [](const edge &x, const edge &y){ return x.w < y.w; });

		vector<int> where(n);
		vector<vector<pair<int, ll>>> c(n);
		vector<ll> lazy(n);
		for (int i = 0; i < n; ++i)
		{
			where[i] = i;
			c[i].push_back({ i, 0 });
		}

		for (auto g : e)
		{
			g.u = where[g.u];
			g.v = where[g.v];
			if (g.u == g.v) continue;

			if (c[g.u].size() < c[g.v].size())
				swap(g.u, g.v);

			lazy[g.u] += (ll)c[g.v].size() * (ll)g.w;
			lazy[g.v] += (ll)c[g.u].size() * (ll)g.w;
			for (auto &i : c[g.v])
			{
				i.S = i.S + lazy[g.v] - lazy[g.u];
				c[g.u].push_back(i);
				where[i.F] = g.u;
			}

			c[g.v].clear();
		}

		vector<ll> ans(n);
		for (auto i : c[where[0]])
			ans[i.F] = i.S + lazy[where[0]];

		cout << "Case " << t+1 << ":\n";
		for (auto &i : ans)
			cout << i << "\n";
	}

	return 0;
}