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

vector<vector<pair<int, pii>>> g;
vector<int> dst;
vector<vector<int>> A;
vector<vector<ll>> cost;

void dfs(int u, int p, ll c1, ll c2){
	A[u][0] = p;
	cost[u][0] = c1;
	cost[u][1] = c2;
	
	for(auto &e : g[u]){
		int v = e.first;
		
		if(v == p)
			continue;
		
		int c = e.second.first;
		int d = e.second.second;
		
		dst[v] = dst[u] + 1;
		
		dfs(v, u, c1 + 1ll * c, c2 + 1ll * d);
	}
}

int lca(int u, int v){
	
	if(dst[u] < dst[v])
		swap(u, v);
	
	int k = dst[u] - dst[v];
	
	for(int i = 19; i >= 0; i--)
		if(k & (1 << i))
			k -= (1 << i), u = A[u][i];
	
	if(u == v)
		return u;
	
	for(int i = 19; i >= 0; i--)
		if(A[u][i] != A[v][i])
			u = A[u][i], v = A[v][i];
	
	return A[u][0];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		g = vector<vector<pair<int, pii>>>(n + 1);
		dst = vector<int>(n + 1);
		A = vector<vector<int>>(n + 1, vector<int>(20));
		cost = vector<vector<ll>>(n + 1, vector<ll>(2));
		
		ll tot = 0;
		
		for(int i = 1; i < n; i++){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			
			tot += 1ll * (c + d);
			
			g[a].push_back({b, {c, d}});
			g[b].push_back({a, {d, c}});
		}
		
		dfs(1, 0, 0, 0);
		
		for(int k = 1; k < 20; k++)
			for(int i = 1; i <= n; i++)
				if(A[i][k - 1])
					A[i][k] = A[A[i][k - 1]][k - 1];
		
		int q;
		cin >> q;
		
		while(q--){
			
			int x, y;
			cin >> x >> y;
			
			int z = lca(x, y);
			
			ll ans = tot - (cost[x][0] + cost[y][1] - cost[z][0] - cost[z][1]);
			
			cout << ans << endl;
		}
	}

	return 0;
}