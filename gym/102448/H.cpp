#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<ll, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll oo = 1e16;

int n, m, k;

vector<int> sources;

vector<ll> d, t;
vector<vector<pii>> g;

void dijkstra(){
	
	d = vector<ll>(n + 1, oo);
	
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for(auto &u : sources){
		pq.push({t[u], u});
		d[u] = t[u];
	}
	
	while(!pq.empty()){
		ll w = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		
		if(w != d[u])
			continue;
		
		for(auto &e : g[u]){
			ll c = e.first;
			int v = e.second;
			
			if(d[v] > d[u] + c + t[v]){
				d[v] = d[u] + c + t[v];
				pq.push({d[v], v});
			}
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n >> m >> k;
	
	g = vector<vector<pii>>(n + 1);
	t = vector<ll>(n + 1);
	
	for(int i = 0; i < m; i++){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		g[a].push_back({c, b});
		g[b].push_back({c, a});
	}
	
	for(int i = 1; i <= n; i++)
		cin >> t[i];
	
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		sources.push_back(x);
	}
	
	dijkstra();
	
	for(int i = 1; i <= n; i++)
		cout << d[i] << endl;

	return 0;
}