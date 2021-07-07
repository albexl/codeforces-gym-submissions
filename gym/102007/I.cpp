#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;

const ll oo = numeric_limits<ll>::max();

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

vector<ll> dijkstra(ll source, vector<vector<pii>> &g){
	
	ll n = (ll)g.size();
	
	vector<ll> d(n, oo);
	d[source] = 0;
	
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	Q.push({0, source});
	
	while(!Q.empty()){
		ll x = Q.top().second;
		ll w = Q.top().first;
		Q.pop();
		
		if(d[x] != w)
			continue;
		
		for(auto &e : g[x]){
			ll v = e.first;
			ll c = e.second;
			if(d[v] > d[x] + c){
				d[v] = d[x] + c;
				Q.push({d[v], v});
			}
		}
	}
	
	return d;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, m, s;
	cin >> n >> m >> s;
	
	vector<ll> p(n);
	vector<vector<pii>> g(n);
	
	ll sum = 0;
	for(ll i = 0; i < n; i++)
		cin >> p[i], sum += p[i];
	
	for(ll i = 0, a, b, c; i < m; i++){
		cin >> a >> b >> c, a--, b--;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	
	vector<ll> c(s), S(s);
	
	for(ll i = 0; i < s; i++)
		cin >> S[i] >> c[i], S[i]--;
	
	vector<vector<ll>> d;
	for(auto &v : S)
		d.push_back(dijkstra(v, g));
	
	ll lo = 0, hi = oo, ans = -1;
	
	while(lo <= hi){
		ll mid = (lo + hi) >> 1ll;
		
		vector<ll> mask(n), cost(1 << s);
		for(ll i = 0; i < s; i++)
			for(ll j = 0; j < n; j++)
				if(d[i][j] <= mid)
					mask[j] |= (1ll << i);
		
		for(ll i = 0; i < n; i++)
			cost[mask[i]] += p[i];
		
		ll n1 = s, n2 = 1 << s, source = n1 + n2, sink = source + 1;
		dinic mf(n1 + n2 + 2);
		
		for(ll i = 0; i < n1; i++)
			mf.add_edge(i, sink, c[i]);
		
		for(ll i = 0; i < n2; i++){
			mf.add_edge(source, i + n1, cost[i]);
			for(ll j = 0; j < n1; j++)
				if(i & (1 << j))
					mf.add_edge(i + n1, j, oo);
		}
		
		if(mf.max_flow(source, sink) >= sum){
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
		
	}
	
	cout << ans << endl;
	
	return 0;
}