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

bool ok(vector<int> &a, vector<int> &b){
	if(a.size() != b.size())
		return false;
	
	for(int i = 0; i < a.size(); i++)
		if(a[i] != b[i])
			return false;
	
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("attack.in", "r", stdin);
	freopen("attack.out", "w", stdout);
	
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	
	a--, b--;
	
	dinic d1(n), d2(n);
	
	for(int i = 0; i < m; i++){
		int x, y, c;
		cin >> x >> y >> c;
		x--, y--;
		d1.add_edge(x, y, 1ll * c);
		d2.add_edge(x, y, 1ll * c);
		d1.add_edge(y, x, 1ll * c);
		d2.add_edge(y, x, 1ll * c);
	}
	
	d1.max_flow(a, b);
	d2.max_flow(b, a);
	
	vector<int> a1, a2, b1, b2;
	
	for(int i = 0; i < n; i++){
		if(d1.level[i] == n)
			a1.push_back(i);
		else
			a2.push_back(i);
		
		if(d2.level[i] != n)
			b1.push_back(i);
		else
			b2.push_back(i);
	}
	
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	sort(b1.begin(), b1.end());
	sort(b2.begin(), b2.end());
	
	if(ok(a1, b1) && ok(a2, b2))
		cout << "UNIQUE" << endl;
	else
		cout << "AMBIGUOUS" << endl;

	return 0;
}