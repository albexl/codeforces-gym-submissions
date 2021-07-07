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

struct graph
{
	int n;
	vector<vector<int>> adj;

	graph(int n) : n(n), adj(n) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int>& operator[](int u) { return adj[u]; }
};

vector<pair<int, int>> bridge_blocks(graph &adj)
{
	int n = adj.n;

	vector<int> num(n), low(n), stk;
	vector<vector<int>> comps;
	vector<pair<int, int>> bridges;

	function<void(int, int, int&)> dfs = [&](int u, int p, int &t)
	{
		num[u] = low[u] = ++t;
		stk.push_back(u);

		// remove if there isn't parallel edges
		sort(adj[u].begin(), adj[u].end()); 

		for (int i = 0, sz = adj[u].size(); i < sz; ++i)
		{
			int v = adj[u][i];

			if (v == p)
			{
				if (i + 1 < sz && adj[u][i + 1] == v)
					low[u] = min(low[u], num[v]);
				continue;
			}

			if (!num[v])
			{
				dfs(v, u, t);
				low[u] = min(low[u], low[v]);

				if (low[v] == num[v])
					bridges.push_back({u, v});
			}
			else low[u] = min(low[u], num[v]);
		}

		if (num[u] == low[u])
		{
			comps.push_back({});
			for (int v = -1; v != u; stk.pop_back())
				comps.back().push_back(v = stk.back());
		}
	};

	for (int u = 0, t; u < n; ++u)
		if (!num[u]) dfs(u, -1, t = 0);

	return bridges;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("bridges.in", "r", stdin);
	freopen("bridges.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	graph g(n);
	
	map<pii, int> mp;
	
	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		a--, b--;
		if(a > b)
			swap(a, b);
		g.add_edge(a, b);
		mp[pii(a, b)] = i + 1;
	}
	
	auto bridges = bridge_blocks(g);
	
	vector<int> ans;
	
	for(auto &el : bridges){
		int a = el.first;
		int b = el.second;
		
		if(a > b)
			swap(a, b);
		
		ans.push_back(mp[pii(a, b)]);
	}
	
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " \n"[i + 1 == ans.size()];
		
	return 0;
}