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

const ll oo = 0x3f3f3f3f3f3f3f3f;

struct min_cost_max_flow
{
	struct edge
	{
		size_t src, dst, rev;
		ll flow, cap;
		ll cost;
	};

	int n;
	vector<vector<edge>> adj;

	min_cost_max_flow(int n) : n(n), adj(n), potential(n), dist(n), back(n) {}

	void add_edge(size_t src, size_t dst, ll cap, ll cost)
	{
		adj[src].push_back({src, dst, adj[dst].size(), 0, cap, cost});
		if (src == dst)
			adj[src].back().rev++;
		adj[dst].push_back({dst, src, adj[src].size() - 1, 0, 0, -cost});
	}

	vector<ll> potential;

	inline ll rcost(const edge &e)
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


	vector<ll> dist;
	vector<edge*> back;

	ll dijkstra(int source, int sink)
	{
		fill(dist.begin(), dist.end(), oo);

		typedef pair<ll, int> node;
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

	pair<ll, ll> max_flow(int source, int sink)
	{
		ll flow = 0;
		ll cost = 0;

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

			ll f = oo;

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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	n++;
	
	vector<vector<ll>> c(n + 1, vector<ll>(n + 1));
	
	min_cost_max_flow mcmf(1 + n + n);
	int s = 0, t = n + n;

	for(int i = 1; i < n; ++i)
		for(int j = i + 1; j <= n; j++)
			cin >> c[i][j];
	
	mcmf.add_edge(s, 1, (ll)k, 0);
	for(int i = 2; i < n; i++)
		mcmf.add_edge(s, i, 1, 0);
	
	for(int i = 1; i <= n; i++)
		mcmf.add_edge(i + n - 1, t, 1, 0);
	
	for(int i = 1; i < n; i++)
		for(int j = i + 1; j <= n; j++)
			mcmf.add_edge(i, j + n - 1, 1, c[i][j]);

	auto ans = mcmf.max_flow(s, t);
	cout << ans.second << endl;

	return 0;
}