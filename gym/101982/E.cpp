#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int maxn = 55;
const ll oo = 0x3f3f3f3f3f3f3f3f;

struct dinic
{
	struct edge
	{
		int src, dst;
		ll cap, flow;
		int rev;
	};

	int n;
	vector<vector<edge>> adj;

	dinic(int n) : n(n), adj(n) {}

	void add_edge(int src, int dst, ll cap)
	{
		adj[src].push_back({ src, dst, cap, 0, (int) adj[dst].size() });
		if (src == dst)
			adj[src].back().rev++;
		adj[dst].push_back({ dst, src, 0, 0, (int) adj[src].size() - 1 });
	}

	vector<int> level, iter;

	ll augment(int u, int t, ll cur)
	{
		if (u == t)
			return cur;
		for (int &i = iter[u]; i < (int) adj[u].size(); ++i)
		{
			edge &e = adj[u][i];
			if (e.cap - e.flow > 0 && level[u] > level[e.dst])
			{
				ll f = augment(e.dst, t, min(cur, e.cap - e.flow));
				if (f > 0)
				{
					e.flow += f;
					adj[e.dst][e.rev].flow -= f;
					return f;
				}
			}
		}
		return 0;
	}

	int bfs(int s, int t)
	{
		level.assign(n, n);
		level[t] = 0;
		queue<int> Q;
		for (Q.push(t); !Q.empty(); Q.pop())
		{
			int u = Q.front();
			if (u == s)
				break;
			for (edge &e : adj[u])
			{
				edge &erev = adj[e.dst][e.rev];
				if (erev.cap - erev.flow > 0
					&& level[e.dst] > level[u] + 1)
				{
					Q.push(e.dst);
					level[e.dst] = level[u] + 1;
				}
			}
		}
		return level[s];
	}

	ll max_flow(int s, int t)
	{
		for (int u = 0; u < n; ++u) // initialize
			for (auto &e : adj[u])
				e.flow = 0;

		ll flow = 0;
		while (bfs(s, t) < n)
		{
			iter.assign(n, 0);
			for (ll f; (f = augment(s, t, oo)) > 0;)
				flow += f;
		} // level[u] == n ==> s-side
		return flow;
	}
};

int n, m, c;

char a[maxn][maxn];
bool flags[maxn][maxn];

ll C[maxn][maxn];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y){
	if(x >= n || x < 0 || y >= m || y < 0)
		return;
	if(a[x][y] != '.' && a[x][y] != 'B')
		return;
	if(flags[x][y])
		return;
	flags[x][y] = true;
	for(int i = 0; i < 4; i++)
		dfs(x + dx[i], y + dy[i]);
}

int get_pos(int x, int y){
	return x * m + y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m >> c;
	swap(n, m);
	
	int xo = 0, yo = 0;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 'B')
				xo = i, yo = j;
		}
	
	vector<ll> cost(c);
	for(int i = 0; i < c; i++)
		cin >> cost[i];
				
	dfs(xo, yo);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
				if(flags[i][j]){
					cout << -1 << endl;
					return 0;
				}
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			if(a[i][j] == '.' || a[i][j] == 'B')
				C[i][j] = oo;
			else
				C[i][j] = cost[a[i][j] - 'a'];
		}
	
	dinic mf(n * m * 2 + 1);
	
	int t = 2 * n * m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int IN = get_pos(i, j);
			int OUT = IN + n * m;
			if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
				mf.add_edge(OUT, t, oo);
			mf.add_edge(IN, OUT, C[i][j]);
			for(int k = 0; k < 4; k++){
				int x = i + dx[k];
				int y = j + dy[k];
				if(x >= 0 && y >= 0 && x < n && y < m)
					mf.add_edge(OUT, get_pos(x, y), oo);
			}
			
		}
	}
	
	cout << mf.max_flow(get_pos(xo, yo), t) << endl;

	return 0;
}