#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<vector<pii>> graph;

typedef complex<ll> point;

double cross(point a, point b) { return (double)a.real() * (double)b.imag() - (double)a.imag() * (double)b.real(); }

ll dot(point a, point b) { return real(conj(a) * b); }

double area2(point a, point b, point c) { return cross(b - a, c - a); }

const double eps = 1e-10;
const ll oo = numeric_limits<ll>::max();

int sign(double x) { return x < -eps ? -1 : x > eps; }

namespace std
{
	bool operator<(const point &a, const point &b)
	{
		return real(a) < real(b) || (real(a) == real(b) && imag(a) < imag(b));
	}
}

struct dynamic_hull
{
	int sz;
	dynamic_hull() : sz(0), hulls() {}

	void add_point(point p)
	{
		++sz;
		hull h;
		h.add_point(p);

		for (hull &_h : hulls)
			if (_h.empty())
			{
				h.swap(_h);
				break;
			}
			else h = merge(h, _h), _h.clear();

		if (!h.empty()) hulls.emplace_back(h);
	}

	ll max_dot(point p)
	{
		ll best = -oo;

		for (hull &h : hulls)
			if (!h.empty()) best = max(best, h.max_dot(p));

		return best;
	}

	struct hull : vector<point>
	{
		void add_point(point p)
		{
			for (int s = size(); s > 1; --s)
				if (sign(area2(at(s - 2), at(s - 1), p)) < 0) break;
				else pop_back();
			push_back(p);
		}

		ll max_dot(point p)
		{
			int lo = 0, hi = (int) size() - 1, mid;

			while (lo < hi)
			{
				mid = (lo + hi) / 2;

				if (dot(at(mid), p) <= dot(at(mid + 1), p))
					lo = mid + 1;
				else hi = mid;
			}

			return dot(at(lo), p);
		}
	};

	static hull merge(const hull &a, const hull &b)
	{
		hull h;
		size_t i = 0, j = 0;

		while (i < a.size() && j < b.size())
			if (a[i] < b[j]) h.add_point(a[i++]);
			else h.add_point(b[j++]);

		while (i < a.size()) h.add_point(a[i++]);

		while (j < b.size()) h.add_point(b[j++]);

		return h;
	}

	vector<hull> hulls;
};

const int maxn = 1e5 + 5;
graph g;
struct heavy_light
{
    int n, heavy[maxn], root[maxn], parent[maxn];
    ll dist[maxn], dp[maxn];
    dynamic_hull LH[maxn], UH[maxn];
    vector<pii> v;

    int dfs(int s, int f)
    {
        parent[s] = f, heavy[s] = -1, dp[s] = 0;
        int size = 1, maxSubtree = 0;

        for (auto u : g[s])
        	if (u.first != f)
			{
        		dist[u.first] = dist[s] + u.second;
				int subtree = dfs(u.first, s);

				if (subtree > maxSubtree)
					heavy[s] = u.first, maxSubtree = subtree;

				size += subtree;
			}

        return size;
    }

    void go(int ROOT = 0)
    {
        n = (int)g.size();

        dist[ROOT] = 0;
        dfs(ROOT, -1);

        for (int i = 0; i < n; ++i)
            if (parent[i] == -1 || heavy[parent[i]] != i)
                for (int u = i; u != -1; u = heavy[u])
                    root[u] = i;

        UH[0].add_point({0, 0});
        LH[0].add_point({0, 0});
    }

    void solve(int u, int f)
    {
    	if(u != 0)
    	{
    		dp[u] = go_up(u) + v[u].first + dist[u] * v[u].second;
    		UH[root[u]].add_point({dist[u], dp[u]});
    		LH[root[u]].add_point({-dist[u], -dp[u]});
    	}

    	for(auto &v : g[u])
    		if(v.first != f && heavy[u] != v.first)
    			solve(v.first, u);
    	if(heavy[u] != -1)
    		solve(heavy[u], u);
    }

    ll go_up(int u)
    {
    	int uu = u;
    	ll mn = oo;
        for (; uu != -1; uu = parent[uu])
        {
        	uu = root[uu];

        	if(LH[uu].sz > 0)
        	{
        		mn = min(mn, -LH[uu].max_dot({-v[u].second, +1}));
        		mn = min(mn, -UH[uu].max_dot({v[u].second, -1}));
        	}
        }
        return mn;
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	g = graph(n);
	for(int i = 1, a, b, c; i < n; ++i)
	{
		cin >> a >> b >> c; --a, --b;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}

	heavy_light hld;
	hld.v = vector<pii>(n);
	for(int i = 1, s, v; i < n; ++i)
		cin >> s >> v, hld.v[i] = {s, v};

	hld.go(0);
	hld.solve(0, -1);

	for(int i = 1; i < n; ++i)
		cout << hld.dp[i] << " \n"[i + 1 == n];

	return 0;
}