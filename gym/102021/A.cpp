#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> graph;

int n, m;
inline int conv(int x, int y)
{
	return x * m + y;
}

bool inside(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

const int maxn = 1e6 + 100;
//const int maxn = 1000;

int N, heavy[maxn], root[maxn], depth[maxn];
int parent[maxn], q[maxn], sz[maxn];

//int dfs(int s, int f, graph &G)
//{
//	parent[s] = f, heavy[s] = -1;
//	int size = 1, maxSubtree = 0;
//
//	for (auto u : G[s])
//		if (u != f)
//		{
//			depth[u] = depth[s] + 1;
//			int subtree = dfs(u, s, G);
//
//			if (subtree > maxSubtree)
//				heavy[s] = u, maxSubtree = subtree;
//
//			size += subtree;
//		}
//
//	return size;
//}

void go(graph &G, int ROOT=0)
{
	N = (int)G.size();

	depth[ROOT] = 0;
//	dfs(ROOT, -1, G);

//	cout << n << endl;
//	vector<vector<int>> V(N, vector<int>(N));
//	for(int i = 0; i < N; ++i)
//		for(auto e : G[i])
//			V[min(i, e)][max(e, i)] = 1;
//
//	int acc = 0;
//	for(int i = 0; i < N; ++i)
//		acc += accumulate(V[i].begin(), V[i].end(), 0);
//	cout << acc << endl;

//	int sc = 0;
//	for(int i = 0; i < N; ++i)
//		sc += G[i].size();
//	cout << sc << endl;

	for(int i = 0; i < N; ++i)
		parent[i] = heavy[i] = -1, sz[i] = 1;

	int b = 0, e = 0;
	q[e++] = ROOT;
	while (b < e)
	{
		int u = q[b++];
		for (auto v : G[u])
			if (v != parent[u])
				depth[v] = depth[u] + 1, parent[v] = u, q[e++] = v;
	}

	for (int i = e - 1; i >= 0; --i)
	{
		int u = q[i];
		if(parent[u] >= 0)
			sz[parent[u]] += sz[u];

		for(auto &v : G[u])
			if(v != parent[u])
			{
				if(heavy[u] == -1 || sz[heavy[u]] < sz[v])
					heavy[u] = v;
			}
	}

	for (int i = 0; i < N; ++i)
		if (parent[i] == -1 || heavy[parent[i]] != i)
			for (int u = i; u != -1; u = heavy[u])
				root[u] = i;
}

int lca(int u, int v)
{
	int ans = 0;
	for (; root[u] != root[v]; v = parent[root[v]])
	{
		if (depth[root[u]] > depth[root[v]])
			swap(u, v);

		ans += abs(depth[v] - depth[parent[root[v]]]);
	}

	ans += abs(depth[v] - depth[u]);
	return ans;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	string s;
	getline(cin, s);

	vector<string> v(n + 1);
	for(int i = 0; i <= n; ++i)
		getline(cin, v[i]);

	graph g(n * m);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			for(int k = 0; k < 4; ++k)
			{
				if(k & 1) continue;

				int ni = i + dx[k];
				int nj = j + dy[k];
				if(!inside(ni, nj)) continue;

				if(k == 2 && v[i + 1][2 * j + 1] != '_')
				{
					int p = conv(i, j), p1 = conv(ni, nj);
					g[p].push_back(p1);
					g[p1].push_back(p);
//					cout << i << " " << j << " -> " << ni << " " << nj << endl;
				}
				if(k == 3 && v[i][2 * j + 1] != '_')
				{
					int p = conv(i, j), p1 = conv(ni, nj);
					g[p].push_back(p1);
					g[p1].push_back(p);
//					cout << i << " " << j << " -> " << ni << " " << nj << endl;
				}
				if(k == 0 && v[i + 1][2 * j + 2] != '|')
				{
					int p = conv(i, j), p1 = conv(ni, nj);
					g[p].push_back(p1);
					g[p1].push_back(p);
//					cout << i << " " << j << " -> " << ni << " " << nj << endl;
				}
				if(k == 1 && v[i + 1][2 * j] != '|')
				{
					int p = conv(i, j), p1 = conv(ni, nj);
					g[p].push_back(p1);
					g[p1].push_back(p);
//					cout << i << " " << j << " -> " << ni << " " << nj << endl;
				}
			}
		}

	go(g);

	ll ans = 0;

	int q; cin >> q;

	int x, y, last; cin >> x >> y;
	last = conv(x - 1, y - 1);

	for(int i = 1, p1; i < q; ++i)
	{
		cin >> x >> y;
		p1 = conv(x - 1, y - 1);
		ans += lca(last, p1);
		last = p1;
	}

	cout << ans << endl;

	return 0;
}