#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

const int oo = 0x3f3f3f3f;

struct dinic
{
	struct edge
	{
		int src, dst;
		int cap, flow;
		int rev;
	};

	int n;
	vector<vector<edge>> adj;

	dinic(int n) : n(n), adj(n) {}

	void add_edge(int src, int dst, int cap)
	{
		adj[src].push_back({ src, dst, cap, 0, (int) adj[dst].size() });
		if (src == dst)
			adj[src].back().rev++;
		adj[dst].push_back({ dst, src, 0, 0, (int) adj[src].size() - 1 });
	}

	vector<int> level, iter;

	int augment(int u, int t, int cur)
	{
		if (u == t)
			return cur;
		for (int &i = iter[u]; i < (int) adj[u].size(); ++i)
		{
			edge &e = adj[u][i];
			if (e.cap - e.flow > 0 && level[u] > level[e.dst])
			{
				int f = augment(e.dst, t, min(cur, e.cap - e.flow));
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

	int max_flow(int s, int t)
	{
		for (int u = 0; u < n; ++u) // initialize
			for (auto &e : adj[u])
				e.flow = 0;

		int flow = 0;
		while (bfs(s, t) < n)
		{
			iter.assign(n, 0);
			for (int f; (f = augment(s, t, oo)) > 0;)
				flow += f;
		} // level[u] == n ==> s-side
		return flow;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n, m, w;
		cin >> n >> m >> w;
		
		dinic mf(n + m + 2);
		
		int s = n + m, t = s + 1;
		
		vector<vector<bool>> places(n, vector<bool>(m)), weapons(n, vector<bool>(w)), spots(m, vector<bool>(w));
		
		for(int i = 0, sz; i < n; i++){
			cin >> sz;
			for(int j = 0, x; j < sz; j++){
				cin >> x, x--;
				places[i][x] = true;
			}
		}
		
		for(int i = 0, sz; i < n; i++){
			cin >> sz;
			for(int j = 0, x; j < sz; j++){
				cin >> x, x--;
				weapons[i][x] = true;
			}
		}
		
		for(int i = 0, sz; i < m; i++){
			cin >> sz;
			for(int j = 0, x; j < sz; j++){
				cin >> x, x--;
				spots[i][x] = true;
			}
		}
		
		for(int i = 0; i < n; i++)
			mf.add_edge(s, i, 1);
		
		for(int i = 0; i < m; i++)
			mf.add_edge(n + i, t, 1);
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(!places[i][j])
					continue;
				bool add = false;
				for(int k = 0; k < w; k++)
					if(weapons[i][k] && spots[j][k])
						add = true;
				if(add)
					mf.add_edge(i, j + n, 1);
			}
		}
		
		cout << mf.max_flow(s, t) << endl;
	}

	return 0;
}