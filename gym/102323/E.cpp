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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int tc;
	cin >> tc;
	
	for(int cases = 1; cases <= tc; cases++){
		
		int n, s;
		cin >> n >> s;
		s--;
		
		graph g(n);
		
		vector<string> name(n);
		
		for(int i = 0; i < n; i++)
			cin >> name[i];
		
		for(int i = 0; i < n; i++){
			int k;
			cin >> k;
			
			while(k--){
				int x;
				cin >> x;
				x--;
				g.add_edge(i, x);
			}
		}
		
		vector<vector<int>> SCC = scc_gabow(g);
		
		cout << "Chain Email #" << cases << ": " << endl;		

		vector<int> ans, id(n);
		
		for(int i = 0; i < SCC.size(); i++)
			for(auto &v : SCC[i])
				id[v] = i;
		
		int N = SCC.size();
		
		vector<vector<int>> G(N);
		
		set<pii> edges;
		
		for(int i = 0; i < n; i++)
			for(auto &v : g[i])
				if(id[i] != id[v])
					edges.insert({id[i], id[v]});
		
		for(auto &e : edges)
			G[e.first].push_back(e.second);
		
		queue<int> Q;
		Q.push(id[s]);
		
		vector<bool> vis(N), more(N), flags(N);
		vis[id[s]] = true;
		
		while(!Q.empty()){
			int x = Q.front();Q.pop();
			
			for(auto &v : G[x]){
				if(!vis[v]){
					vis[v] = true;
					Q.push(v);
				}
			}	
		}
		
		
		for(int i = 0; i < N; i++)
			if(vis[i] && SCC[i].size() > 1){
				flags[i] = true;
				Q.push(i);
			}
				
		
		while(!Q.empty()){
			int x = Q.front();Q.pop();
			
			for(auto &v : G[x]){
				if(!flags[v]){
					flags[v] = true;
					Q.push(v);
				}
			}	
		}
		
		for(int i = 0; i < N; i++)
			if(flags[i])
				for(auto &v : SCC[i])
					ans.push_back(v);

		sort(ans.begin(), ans.end());
		
		if(ans.size() == 0)
			cout << "Safe chain email!" << endl;
		else{
			for(int i = 0; i < ans.size(); i++)
				cout << name[ans[i]] << " \n"[i + 1 == ans.size()];
		}
		
		cout << endl;
	}
	

	return 0;
}