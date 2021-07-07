#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> graph;

const int maxn = 3e5 + 5;

int ft[maxn];

void update(int p, int v)
{
	for(; p < maxn; p += p & -p)
		ft[p] += v;
}

int query(int p)
{
	int ans = 0;
	for(; p > 0; p -= p & -p)
		ans += ft[p];
	return ans;
}

int query(int a, int b)
{
	return query(b) - query(a - 1);
}

int heavy[maxn], depth[maxn];
int dfs(int u, int f, graph &g)
{
	heavy[u] = -1;
	int sz = 1, maxsubtree = 0;
	for(auto &v : g[u])
		if(v != f)
		{
			depth[v] = depth[u] + 1;
			int subtree = dfs(v, u, g);
			if(subtree > maxsubtree)
				maxsubtree = subtree, heavy[u] = v;
			sz += subtree;
		}
	return sz;
}

void use(int u, int f, graph &g, int add)
{
	update(depth[u], add);
	for(auto &v : g[u])
		if(v != f)
			use(v, u, g, add);
}

ll n, l, r;
void inc(int u, int f, int root, graph &g, ll &ans)
{
	ans += query(2 * depth[root] + l - depth[u], 2 * depth[root] + r - depth[u]);
	for(auto &v : g[u])
		if(v != f)
			inc(v, u, root, g, ans);
}

void solve(int u, int f, graph &g, ll &ans, bool keep)
{
	for(auto &v : g[u])
		if(v != f && v != heavy[u])
			solve(v, u, g, ans, false);

	if(heavy[u] >= 0)
		solve(heavy[u], u, g, ans, true);

	ans += query(depth[u] + l, depth[u] + r);
	update(depth[u], +1);

	for(auto &v : g[u])
		if(v != f && v != heavy[u])
			inc(v, u, u, g, ans), use(v, u, g, +1);

	if(!keep)
		use(u, f, g, -1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("awesome.in", "r", stdin);

	int c;
	cin >> c;

	while(c--)
	{
		cin >> n >> l >> r;

		l = n - l - 1;
		r = n - r - 1;

		if(r < l)
			swap(l, r);

		graph g(n);
		for(int i = 1, a, b; i < n; ++i)
		{
			cin >> a >> b, --a, --b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		depth[0] = 1;
		dfs(0, -1, g);

		ll ans = 0;
		solve(0, -1, g, ans, false);

		cout << ans << endl;
	}

	return 0;
}