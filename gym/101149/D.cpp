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
		
		int xo, yo, xi, yi;
		
	};

	int n;
	vector<vector<edge>> adj;

	dinic(int n) : n(n), adj(n) {}

	void add_edge(int src, int dst, ll cap, int xo, int yo, int xi, int yi)
	{
		adj[src].push_back({ src, dst, cap, 0, (int) adj[dst].size(), xo, yo, xi, yi });
		if (src == dst)
			adj[src].back().rev++;
		adj[dst].push_back({ dst, src, 0, 0, (int) adj[src].size() - 1, xo, yo, xi, yi });
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

int n, m, xo, yo;

bool flags[maxn][maxn];

ll C[maxn][maxn];
char ans[maxn][maxn];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


int get_pos(int x, int y){
	return x * m + y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m >> xo >> yo;
	
	xo--, yo--;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> C[i][j];
	
	C[xo][yo] = oo;
	
	dinic mf(n * m * 2 + 1);
	
	int t = 2 * n * m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int IN = get_pos(i, j);
			int OUT = IN + n * m;
			if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
				mf.add_edge(OUT, t, oo, i, j, n, m);
			mf.add_edge(IN, OUT, C[i][j], i, j, i, j);
			for(int k = 0; k < 4; k++){
				int x = i + dx[k];
				int y = j + dy[k];
				if(x >= 0 && y >= 0 && x < n && y < m)
					mf.add_edge(OUT, get_pos(x, y), oo, i, j, x, y);
			}
			
		}
	}
	
	cout << mf.max_flow(get_pos(xo, yo), t) << endl;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			ans[i][j] = '.';
	
	for(int i = 0; i < mf.adj.size(); i++){
		for(auto &e : mf.adj[i]){
			
			if(e.xo == e.xi && e.yo == e.yi && mf.level[e.src] == 2 * n * m + 1 && mf.level[e.dst] != 2 * n * m + 1){
				//cout << e.src << " " << e.dst << " " << e.cap << " " << e.flow << " " << e.rev << " " << e.xo << " " << e.yo << " " << e.xi << " " << e.yi << endl;
				//cout << mf.level[e.src] << " " << mf.level[e.dst] << endl;
				ans[e.xo][e.yo] = 'X';
			}
				
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << ans[i][j];
		cout << endl;
	}
		

	return 0;
}