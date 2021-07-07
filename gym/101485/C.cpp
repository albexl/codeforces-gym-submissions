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

struct line { point p, q; };
using segment = line;

ll dot(point a, point b) { return real(conj(a) * b); }

ll cross(point a, point b) { return imag(conj(a) * b); }

// where is c with respect to a->b
int ccw(point a, point b, point c)
{
	b -= a; c -= a;
	if (cross(b, c) > 0) return +1; // counter clockwise
	if (cross(b, c) < 0) return -1; // clockwise
	if (dot(b, c) < 0) return +2; // c--a--b on line
	if (dot(b, b) < dot(c, c)) return -2; // a--b--c on line
	return 0;
}

bool intersectSS(const segment &s, const segment &t)
{
	return ccw(s.p, s.q, t.p) * ccw(s.p, s.q, t.q) <= 0
			&& ccw(t.p, t.q, s.p) * ccw(t.p, t.q, s.q) <= 0;
}

int main()
{
	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int w, p;
	cin >> w >> p;
	vector<point> a(w);
	for (auto &i : a)
	{
		int x, y;
		cin >> x >> y;
		i = { x, y };
	}

	vector<segment> v(p);
	for (int i = 0, s, x, y; i < p; ++i)
	{
		cin >> s >> x >> y;
		--s;
		v[i] = { a[s], { x, y } };
	}

	int n = p;
	vector<vector<int>> adj(n);
	for (int i = 0; i < p; ++i)
		for (int j = i+1; j < p; ++j)
			if (intersectSS(v[i], v[j]) && v[i].p != v[j].p)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}

	vector<int> mark(n, -1);
	function<bool(int, int)> dfs = [&](int u, int c)
	{
		mark[u] = c;
		for (auto v : adj[u])
		{
			if (mark[v] == -1)
			{
				if (!dfs(v, !c)) return false;
			}

			if (mark[v] == c) return false;
		}
		return true;
	};

	for (int i = 0; i < n; ++i)
		if (mark[i] == -1)
		{
			if (!dfs(i, 0))
			{
				cout << "impossible\n";
				return 0;
			}
		}

	cout << "possible\n";

	return 0;
}