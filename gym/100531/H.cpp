#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715;
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second

ll cross(point a, point b) { return imag(conj(a) * b); }
ll cross(point a, point b, point c) { return cross(b - a, c - a); } // cross

struct point3d
{
	ll x, y, z;
	bool operator<(const point3d &t) const
	{
		return make_pair(x, make_pair(y, z)) < make_pair(t.x, make_pair(t.y, t.z));
	}
	void print()
	{
		cout << x << " " << y << " " << z << "\n";
	}
};

struct triangle
{
	point a, b, c;
};

bool point_inside(triangle t, point p)
{
	ll r = 0;
	r += abs(cross(p, t.a, t.b));
	r += abs(cross(p, t.a, t.c));
	r += abs(cross(p, t.c, t.b));
	r -= abs(cross(t.a, t.b, t.c));
	return r == 0;
}

int main()
{
	//#ifdef DGC
		freopen("hiking.in", "r", stdin);
		freopen("hiking.out", "w", stdout);
	//#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;

	int id = 0;
	map<point3d, int> mp;
	vector<point3d> rmp;
	vector<vector<point3d>> t;
	for (int i = 0; i < n; ++i)
	{
		vector<point3d> v(3);
		for (auto &j : v)
			cin >> j.x >> j.y >> j.z;

		t.push_back(v);
		for (auto &j : v)
			if (mp.find(j) == mp.end())
				mp[j] = id++;
	}

	point3d S, T;
	cin >> S.x >> S.y >> S.z >> T.x >> T.y >> T.z;
	if (mp.find(S) == mp.end())
		mp[S] = id++;
	if (mp.find(T) == mp.end())
		mp[T] = id++;

	rmp.resize(id);
	for (auto &i : mp)
		rmp[i.S] = i.F;

	int source = mp[S];
	int dest = mp[T];

	vector<vector<pair<int, ll>>> adj(id);
	for (auto &k : t)
	{
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (i != j)
					adj[mp[k[i]]].push_back({ mp[k[j]], max(k[i].z, k[j].z) });

		if (point_inside({ { k[0].x, k[0].y }, { k[1].x, k[1].y }, { k[2].x, k[2].y } }, { S.x, S.y }))
		{
			for (auto &i : k)
			{
				adj[mp[S]].push_back({ mp[i], max(i.z, S.z) });
				//adj[mp[i]].push_back({ mp[S], max(i.z, S.z) });
			}
		}

		if (point_inside({ { k[0].x, k[0].y }, { k[1].x, k[1].y }, { k[2].x, k[2].y } }, { T.x, T.y }))
		{
			for (auto &i : k)
			{
				//adj[mp[T]].push_back({ mp[i], max(i.z, T.z) });
				adj[mp[i]].push_back({ mp[T], max(i.z, T.z) });
			}
		}
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	vector<ll> dist(id, numeric_limits<ll>::max());
	vector<int> parent(id, -1);
	dist[source] = S.z;
	pq.push({ S.z, source });

	while (!pq.empty())
	{
		int u; ll w;
		tie(w, u) = pq.top();
		pq.pop();

		if (w != dist[u]) continue;

		for (auto v : adj[u])
			if (dist[v.F] > max(w, v.S))
			{
				dist[v.F] = max(w, v.S);
				pq.push({ dist[v.F], v.F });
				parent[v.F] = u;
			}
	}

	vector<int> ans;
	int u = dest;
	while (u != -1)
	{
		ans.push_back(u);
		u = parent[u];
	}

	reverse(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto &i : ans)
		rmp[i].print();

	return 0;
}