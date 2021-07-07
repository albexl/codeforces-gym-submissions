#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;

struct graph
{
	int L, R;
	vector<vector<int>> adj;

	graph(int L, int R) : L(L), R(R), adj(L + R) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v + L);
		adj[v + L].push_back(u);
	}

	int maximum_matching()
	{
		vector<int> level(L), mate(L + R, -1);

		function<bool(void)> levelize = [&]()
		{
			queue<int> Q;
			for (int u = 0; u < L; ++u)
			{
				level[u] = -1;
				if (mate[u] < 0)
				{
					level[u] = 0;
					Q.push(u);
				}
			}
			while (!Q.empty())
			{
				int u = Q.front(); Q.pop();
				for (int w : adj[u])
				{
					int v = mate[w];
					if (v < 0) return true;
					if (level[v] < 0)
					{
						level[v] = level[u] + 1;
						Q.push(v);
					}
				}
			}
			return false;
		};

		function<bool(int)> augment = [&](int u)
		{
			for (int w : adj[u])
			{
				int v = mate[w];
				if (v < 0 || (level[v] > level[u] && augment(v)))
				{
					mate[u] = w;
					mate[w] = u;
					return true;
				}
			}
			return false;
		};
		int match = 0;
		while (levelize())
			for (int u = 0; u < L; ++u)
				if (mate[u] < 0 && augment(u))
					++match;
		return match;
	}
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
 	int t;
 	cin >> t;

 	while(t--){

 		int n, m;
 		cin >> n >> m;

 		vector<vector<int>> g(n);
 		vector<pii> edges;

 		for(int i = 0, a, b; i < m; i++){
 			cin >> a >> b;
 			a--, b--;
 			g[a].push_back(b);
 			g[b].push_back(a);
 			edges.push_back({a, b});
 		}

 		vector<int> color(n, -1);
 		queue<int> Q;
 		Q.push(0);
 		color[0] = 0;
 		while(!Q.empty()){
 			int u = Q.front();Q.pop();
 			for(auto &v : g[u]){
 				if(color[v] == -1){
 					if(color[u] == 0)
 						color[v] = 1;
 					else
 						color[v] = 0;
 					Q.push(v);
 				}
 			}
 		}

 		int idx1 = 0, idx2 = 0;
 		vector<int> pos(n, -1);
 		int l = 0, r = 0;
 		for(int i = 0; i < n; i++){
 			if(color[i] == 1){
 				l++;
 				pos[i] = idx1++;
 			}
 			else{
 				r++;
 				pos[i] = idx2++;
 			}
 		}

 		graph G(l, r);
 		for(auto &e : edges){
 			int a = e.first;
 			int b = e.second;

 			if(color[a] == 0)
 				swap(a, b);
 			a = pos[a];
 			b = pos[b];

 			G.add_edge(a, b);
 		}

 		int ans = G.maximum_matching();

 		cout << n - ans << endl;

 	}

    return 0;
}