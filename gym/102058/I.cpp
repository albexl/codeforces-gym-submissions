#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<pii>> graph;

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
		{
			bool ok = false;
			for (int u = 0; u < n; ++u)
				for (edge &e : adj[u])
					if (e.cap > 0 && rcost(e) < 0)
						potential[e.dst] += rcost(e), ok = true;
			if(!ok) break;
		}
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	graph g(n);
	for(int i = 1, a, b, c; i < n; ++i)
	{
		cin >> a >> b >> c;
		--a, --b;
		g[a].emplace_back(b, -c);
		g[b].emplace_back(a, -c);
	}

	vector<int> col(n, -1);
	col[0] = 0;

	queue<int> q;
	q.push(0);

	while(!q.empty())
	{
		int x = q.front();
		q.pop();

		for(auto &e : g[x])
			if(col[e.first] == -1)
				col[e.first] = (col[x] + 1) % 2, q.push(e.first);
	}

	min_cost_max_flow<ll, ll> d(n + 2 + 1);
	int s = n, tt = s + 1, t = tt + 1;

	d.add_edge(tt, t, k, 0);
	for(int i = 0; i < n; ++i)
	{
		if(col[i])
			d.add_edge(i, tt, 1, 0);
		else
		{
			for(auto &e : g[i])
				d.add_edge(i, e.first, 1, e.second);
			d.add_edge(s, i, 1, 0);
		}
	}

	auto ans = d.max_flow(s, t);

	if(ans.first < k)
		cout << "Impossible" << endl;
	else
		cout << -ans.second << endl;

	return 0;
}