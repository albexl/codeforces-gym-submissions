#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second
#define endl '\n'
 
 
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
 
	int add_node()
	{
		adj.push_back({});
		return n++;
	}
 
	vector<int>& operator[](int u) { return adj[u]; }
};
 
vector<vector<int>> biconnected_components(graph &adj)
{
	int n = adj.n;
	int t = 0;

	vector<int> num(n), low(n), art(n), stk;
	vector<vector<int>> comps;

	function<void(int, int)> dfs = [&](int u, int p)
	{
		num[u] = low[u] = ++t;
		stk.push_back(u);

		for (int v : adj[u]) if (v != p)
		{
			if (!num[v])
			{
				dfs(v, u);
				low[u] = min(low[u], low[v]);

				if (low[v] >= num[u])
				{
					art[u] = (num[u] > 1 || num[v] > 2);

					comps.push_back({u});
					while (comps.back().back() != v)
						comps.back().push_back(stk.back()),
						stk.pop_back();
				}
			}
			else low[u] = min(low[u], num[v]);
		}
	};

	for (int u = 0, t; u < n; ++u)
		if (!num[u]) t = 0, dfs(u, -1);


	return comps;
}
 
graph g(1);
int cnt;
vector<int> pi, cycle, id;
vector<bool> used, mark;
bool found;
 
void dfs(int u, int p){
 
	if(found)
		return;
 
	pi[u] = p;
	used[u] = true;
 
	for(auto &v : g[u]){
		if(v != p){
 
			if(!used[v])
				dfs(v, u);
			else{
				found = true;
				int x = pi[u];
 
				cycle.push_back(u);
				while(x != v){
					cycle.push_back(x);
					x = pi[x];
				}
				cycle.push_back(v);
			}
 
			if(found)
				return;
		}
	}
}
 
vector<vector<int>> solve(vector<int> &comp){
 
//	cerr << "solving" << endl;
 
	for(auto &y : comp){
		if(!used[y]){
 
			found = false;
			cycle.clear();
			dfs(y, -1);
 
			if(found){
 
				set<pii> edges;
 
				++cnt;
				for(int i = 0; i < (int)cycle.size(); i++){
					int el = cycle[i];
					int u = cycle[(i + 1) % cycle.size()];
					id[el] = cnt;
 
					edges.insert(pii(el, u));
					edges.insert(pii(u, el));
				}
 
 
//				cout << "cycle" << endl;
//				for(auto &val : cycle)
//					cout << val + 1 << " ";
//				cout << endl;
 
				vector<int> q;
 
				for(auto &elem : cycle){
 
					q.clear();
					q.push_back(elem);
 
					mark[elem] = true;
 
					pi[elem] = -1;
 
					int s = elem;
					int t = -1;
 
					for(int i = (int)q.size() - 1; i < (int)q.size(); i++){
 
						int u = q[i];
 
						for(auto &v : g[u]){
 
							if(edges.find(pii(u, v)) != edges.end())
								continue;
 
							if(id[v] == cnt && v != elem){
								pi[v] = u;
								t = v;
								break;
							}
 
							if(!mark[v]){
								mark[v] = true;
								q.push_back(v);
								pi[v] = u;
							}
						}
 
						if(t != -1)
							break;
					}
 
					vector<vector<int>> paths(3);
 
					if(t != -1){
 
						int x = t;
						while(x != s){
							paths[0].push_back(x);
							x = pi[x];
						}
						paths[0].push_back(s);
 
						reverse(paths[0].begin(), paths[0].end());
 
						for(int i = 0; i < (int)cycle.size(); i++){
							if(cycle[i] == s){
 
								int j = i;
								while(cycle[j] != t){
									paths[1].push_back(cycle[j]);
									j++;
									j %= (cycle.size());
								}
								paths[1].push_back(t);
 
 
								j = i;
								while(cycle[j] != t){
									paths[2].push_back(cycle[j]);
									j--;
									j += cycle.size();
									j %= (cycle.size());
								}
								paths[2].push_back(t);
 
								break;
							}
						}
 
						return paths;
					}
				}
			}
 
			break;
		}
	}
 
	return {};
}
 
int main()
{
//	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		freopen("grand.in", "r", stdin);
		freopen("grand.out", "w", stdout);
	//#endif
 
	ios_base::sync_with_stdio(0), cin.tie(0);
 
	int t;
	cin >> t;
 
	while(t--){
 
		int n, m;
		cin >> n >> m;
 
		g = graph(n);
		cnt = 0;
		id = vector<int>(n, -1);
		used = vector<bool>(n, false);
		mark = vector<bool>(n, false);
		pi = vector<int>(n, -1);
 
		for(int i = 0, a, b; i < m; i++){
			cin >> a >> b;
			a--, b--;
			g.add_edge(a, b);
		}
 
		vector<vector<int>> comps = biconnected_components(g);
 
		bool ok = false;
 
		for(auto &c : comps){
 
			auto ans = solve(c);
 
			if(!ans.empty()){
 
				ok = true;
				cout << ans[0][0] + 1 << " " << ans[0].back() + 1 << endl;
 
				for(int i = 0; i < 3; i++){
					cout << ans[i].size();
					for(auto &el : ans[i])
						cout << " " << el + 1;
					cout << endl;
				}
				break;
			}
		}
 
		if(!ok)
			cout << -1 << endl;
 
	}
 
	return 0;
}