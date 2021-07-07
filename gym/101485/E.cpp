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

struct graph
{
	int L, R;
	vector<vector<int>> adj;

	graph(int L, int R) : L(L), R(R), adj(L + R) {}

	void add(int u, int v)
	{
		adj[u].push_back(v + L);
		adj[v + L].push_back(u);
	}

	pair<int, vector<int>> match()
	{
		vector<int> visited(L), mate(L + R, -1);
		function<bool(int)> augment = [&](int u)
		{
			if (visited[u]) return false;
			visited[u] = true;
			for (int w : adj[u])
			{
				int v = mate[w];
				if (v < 0 || augment(v))
				{
					mate[u] = w;
					mate[w] = u;
					return true;
				}
			}
			return false;
		};

		int mat = 0;
		for (int u = 0; u < L; ++u)
		{
			fill(visited.begin(), visited.end(), 0);
			if (augment(u))
				++mat;
		}
		return { mat, mate };
	}
};

int main()
{
	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<pair<ll, ll>> a(n);
	for (auto &i : a) cin >> i.F >> i.S;

	vector<ll> s;
	for (auto i : a)
	{
		s.push_back(i.F + i.S);
		s.push_back(i.F - i.S);
		s.push_back(i.F * i.S);
	}

	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	map<pair<int, int>, char> mp;
	graph g(n, s.size());
	for (int i = 0; i < n; ++i)
	{
		int p = lower_bound(s.begin(), s.end(), a[i].F + a[i].S) - s.begin();
		g.add(i, p);
		mp[{ i, p }] = '+';

		p = lower_bound(s.begin(), s.end(), a[i].F - a[i].S) - s.begin();
		g.add(i, p);
		mp[{ i, p }] = '-';

		p = lower_bound(s.begin(), s.end(), a[i].F * a[i].S) - s.begin();
		g.add(i, p);
		mp[{ i, p }] = '*';
	}

	auto ans = g.match();
	if (ans.F != n)
	{
		cout << "impossible\n";
		return 0;
	}

	for (int i = 0; i < n; ++i)
	{
		debug(i, ans.S[i])
		cout << a[i].F << " " << mp[{ i, ans.S[i] - n }] << " " << a[i].S << " = " << s[ans.S[i] - n] << "\n";
	}

	return 0;
}