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
		vector<int> visited(L), mate(L + R, -1);
		function<bool(int)> augment = [&](int u)
		{
			if (visited[u]) return false;
			visited[u] = true;
			for (int w : adj[u])
			{
				int v = mate[w];
				if (v < 0 || augment(v))
				{
					mate[u] = w;
					mate[w] = u;
					return true;
				}
			}
			return false;
		};
		int match = 0;
		for (int u = 0; u < L; ++u)
		{
			fill(visited.begin(), visited.end(), 0);
			if (augment(u))
				++match;
		}
		
		return match;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		
		graph g(n, n);
		set<pii> s;
		
		for(int i = 0, a, b; i < m; i++){
			cin >> a >> b;
			a--;
			b--;
			s.insert({a, b});
		}
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(s.find({i, j}) == s.end())
					g.add_edge(i, j);

		cout << 2 * n - g.maximum_matching() << endl;
	}

	return 0;
}