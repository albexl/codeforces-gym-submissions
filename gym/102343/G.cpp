#include<bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define MAX
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> tri;
 
template<typename flow_type, typename cost_type>
struct min_cost_max_flow
{
	struct edge
	{
		size_t src, dst, rev;
		flow_type flow, cap;
		cost_type cost;
	};

	int n;
	vector<vector<edge>> adj;

	min_cost_max_flow(int n) : n(n), adj(n), potential(n), dist(n), back(n) {}

	void add_edge(size_t src, size_t dst, flow_type cap, cost_type cost)
	{
		adj[src].push_back({src, dst, adj[dst].size(), 0, cap, cost});
		if (src == dst)
			adj[src].back().rev++;
		adj[dst].push_back({dst, src, adj[src].size() - 1, 0, 0, -cost});
	}

	vector<cost_type> potential;

	inline cost_type rcost(const edge &e)
	{
		return e.cost + potential[e.src] - potential[e.dst];
	}

	void bellman_ford(int source)
	{
		for (int k = 0; k < n; ++k)
			for (int u = 0; u < n; ++u)
				for (edge &e : adj[u])
					if (e.cap > 0 && rcost(e) < 0) 
						potential[e.dst] += rcost(e);
	}

	const cost_type oo = numeric_limits<cost_type>::max();

	vector<cost_type> dist;
	vector<edge*> back;

	cost_type dijkstra(int source, int sink)
	{
		fill(dist.begin(), dist.end(), oo);

		typedef pair<cost_type, int> node;
		priority_queue<node, vector<node>, greater<node>> pq;

		for (pq.push({dist[source] = 0, source}); !pq.empty();)
		{
			node p = pq.top(); pq.pop();

			if (dist[p.second] < p.first) continue;
			if (p.second == sink) break;

			for (edge &e : adj[p.second])
				if (e.flow < e.cap && 
					dist[e.dst] > dist[e.src] + rcost(e))
				{
					back[e.dst] = &e;
					pq.push({dist[e.dst] = dist[e.src] + rcost(e), 
							 e.dst});
				}
		}

		return dist[sink];
	}

	pair<flow_type, cost_type> max_flow(int source, int sink)
	{
		flow_type flow = 0;
		cost_type cost = 0;

		for (int u = 0; u < n; ++u)
			for (edge &e : adj[u]) e.flow = 0;

		potential.assign(n, 0);
		dist.assign(n, 0);
		back.assign(n, nullptr);

		bellman_ford(source); // remove negative costs

		while (dijkstra(source, sink) < oo)
		{
			for (int u = 0; u < n; ++u)
				if (dist[u] < dist[sink])
					potential[u] += dist[u] - dist[sink];

			flow_type f = numeric_limits<flow_type>::max();

			for (edge *e = back[sink]; e; e = back[e->src])
				f = min(f, e->cap - e->flow);
			for (edge *e = back[sink]; e; e = back[e->src])
				e->flow += f, adj[e->dst][e->rev].flow -= f;

			flow += f;
			cost += f * (potential[sink] - potential[source]);

		}
		return {flow, cost};
	}
};

const int maxn = 35;

char a[maxn][maxn];
int idx[maxn][maxn];
int pos = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	

	int n, m;
	cin >> n >> m;

	int xb = -1, yb = -1, xc = -1, yc = -1, xf = -1, yf = -1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			idx[i][j] = pos++;

			if(a[i][j] == 'B')
				xb = i, yb = j;
			if(a[i][j] == 'C')
				xc = i, yc = j;
			if(a[i][j] == 'F')
				xf = i, yf = j;

		}
	}

	int SZ = pos * 2;

	// cout << SZ << endl;

	min_cost_max_flow<int, int> mcmf(SZ + 1);

	int source = SZ;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int u = idx[i][j];
			int v = u + SZ / 2;

			if(a[i][j] == 'x')
				continue;

			mcmf.add_edge(u, v, 1, 0);

			for(int k = 0; k < 4; k++){
				int x = i + dx[k];
				int y = j + dy[k];

				if(x >= 0 && y >= 0 && x < n && y < m && a[x][y] != 'x')
					mcmf.add_edge(v, idx[x][y], 1, 1);
				
			}
		}
	}

	mcmf.add_edge(source, idx[xb][yb], 1, 0);
	mcmf.add_edge(source, idx[xc][yc], 1, 0);

	auto ans = mcmf.max_flow(source, idx[xf][yf]);

	// cout << ans.first << " " << ans.second << endl;

	if(ans.first != 2)
		cout << -1 << endl;
	else
		cout << ans.second << endl;


	return 0;
}