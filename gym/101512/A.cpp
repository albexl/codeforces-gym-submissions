#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		
		int x, g, t;
		cin >> x >> g >> t;
		
		vector<bool> hosp(n + 1);
		
		int m;
		cin >> m;
		
		int SZ = n * (t + 1) + 2;
		int source = n * (t + 1), sink = source + 1;
		
		dinic mf(SZ);
		
		//cerr << "here" << endl;
		
		while(m--){
			int h;
			cin >> h;
			hosp[h] = true;
		}
		
		vector<vector<int>> idx(n + 1, vector<int>(t + 1));
		int cnt = 0;
		
		//cerr << "here" << endl;
		//cerr << SZ << " " << source << " " << sink << endl;
		
		
		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= t; j++)	
				idx[i][j] = cnt++;
		
		//cerr << "here" << endl;
		
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < t; j++){
				int u = idx[i][j];
				int v = idx[i][j + 1];
				mf.add_edge(u, v, g);
			}
		}
		
		//cerr << "here" << endl;
		
		mf.add_edge(source, idx[x][0], g);
		
		//cerr << "here" << endl;
		
		for(int i = 1; i <= n; i++){
			if(hosp[i]){
				for(int j = 0; j <= t; j++){
					int u = idx[i][j];
					mf.add_edge(u, sink, g);
				}
			}
		}
		
		//cerr << "here" << endl;
		
		int r;
		cin >> r;
		
		while(r--){
			int a, b, p, w;
			cin >> a >> b >> p >> w;
			
			for(int j = 0; j <= t; j++){
				if(j + w <= t){
					int u = idx[a][j];
					int v = idx[b][j + w];
					mf.add_edge(u, v, p);
				}
			}
		}
		
		//cerr << "here" << endl;
		
		cout << mf.max_flow(source, sink) << endl;
		
		
	}

	return 0;
}