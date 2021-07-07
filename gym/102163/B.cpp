#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef pair<int, int> pii;

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

graph bridge_blocks(graph &adj)
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

	// this is for build the bridge-block tree
	function<graph()> build_tree = [&]()
	{
		vector<int> id(n);

		for (int i = 0; i < (int) comps.size(); ++i)
			for (int u : comps[i]) id[u] = i;

		graph tree(comps.size());

		for (auto &e : bridges)
			tree.add_edge(id[e.first], id[e.second]);

		return tree;
	};

	return build_tree();
}

pii bfs(int s, graph &g){
    int n = g.n;
    queue<int> Q;
    Q.push(s);
    vector<int> d(n, -1);
    d[s] = 0;
    int last = s;
    while(!Q.empty()){
        int v = Q.front();Q.pop();
        last = v;
        for(auto &u : g[v]){
            if(d[u] == -1){
                d[u] = d[v] + 1;
                Q.push(u);
            }
        }
    }
    
    return {last, d[last]};
}

int get_diam(graph &g){
    
    pii A = bfs(0, g);
    pii B = bfs(A.first, g);
    return B.second;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    
	    graph g(n);
	    for(int i = 0, a, b; i < m; i++){
	        cin >> a >> b;
	        a--;
	        b--;
	        g.add_edge(a, b);
	    }
	    
	    graph t = bridge_blocks(g);
	    
	    int bridges = t.n - 1;
	    int diam = get_diam(t);
	    
	    cout << bridges - diam << endl;
	    
	}
	

	return 0;
}