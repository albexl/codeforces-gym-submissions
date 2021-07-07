#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

struct graph
{
	int n;
	vector<vector<int>> adj;

	graph(int n) : n(n), adj(n) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
	}

	vector<int>& operator[](int u) { return adj[u]; }
};

vector<vector<int>> scc_gabow(graph &adj)
{
	int n = adj.n;

	vector<vector<int>> scc;
	vector<int> S, B, I(n);

	function<void(int)> dfs = [&](int u)
	{
		B.push_back(I[u] = S.size());
		S.push_back(u);

		for (int v : adj[u])
			if (!I[v]) dfs(v);
			else while (I[v] < B.back()) B.pop_back();

		if (I[u] == B.back())
		{
			scc.push_back({});
			for (B.pop_back(); I[u] < S.size(); S.pop_back())
			{
				scc.back().push_back(S.back());
				I[S.back()] = n + scc.size();
			}
		}
	};

	for (int u = 0; u < n; ++u)
		if (!I[u]) dfs(u);

	return scc; // in reverse topological order
}

map<pii, int> scc_dist;
set<pii> edges;

void solve(vector<int> &scc){

	sort(scc.begin(), scc.end());

	do{
		for(int i = 1; i < scc.size(); i++){
			int u = scc[i - 1], v = scc[i];
			if(edges.find(pii(u, v)) == edges.end())
				break;
			scc_dist[pii(scc[0], scc[i])] = max(scc_dist[pii(scc[0], scc[i])], i);
		}

	}while(next_permutation(scc.begin(), scc.end()) );

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	graph g(n);

	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		a--, b--;
		g.add_edge(a, b);
		edges.insert({a, b});
	}

	auto SCC = scc_gabow(g);

	int N = (int)SCC.size();
	vector<int> comp(n);

	for(int i = 0; i < N; i++){

		solve(SCC[i]);

		for(auto &el : SCC[i])
			comp[el] = i;
	}

	vector<int> dp(n), out(n);

	for(auto &scc : SCC){

		for(auto &u : scc)
			for(auto &v : g[u])
				if(comp[v] != comp[u])
					out[u] = max(out[u], dp[v]);

		for(auto &u : scc)
			for(auto &v : scc)
				dp[u] = max(dp[u], 1 + scc_dist[pii(u, v)] + out[v]);
	}

	int ans = 0;

	for(int i = 0; i < n; i++)
		ans = max(ans, dp[i]);

	cout << ans << endl;

	return 0;
}