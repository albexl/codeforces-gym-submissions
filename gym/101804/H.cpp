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

const int maxn = 1e3 + 5;
const int oo = 2e9;

int n, m;
int d[maxn][maxn];
vector<pii> g[maxn];

void dijkstra(int s){
	
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < n; j++)
			d[i][j] = oo;

	d[s][0] = 0;
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	pq.push({0, {s, 0}});
	
	while(!pq.empty()){
		int w = pq.top().first;
		int u = pq.top().second.first;
		int k = pq.top().second.second;
		pq.pop();
		
	//	cout << u << " " << k << " " << w << endl;
		
		if(w != d[u][k])
			continue;
		
		if(k == n)
			continue;
		
		for(auto &e : g[u]){
			int v = e.first;
			int c = e.second;
			
			if(d[v][k + 1] > d[u][k] + c){
				d[v][k + 1] = d[u][k] + c;
				pq.push({d[v][k + 1], {v, k + 1}});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 0, a, b, c; i < m; i++){
		cin >> a >> b >> c;
		g[a].push_back({b, c});
	}
	
	dijkstra(1);
	
	int q;
	cin >> q;
	
	while(q--){
		int v, k;
		cin >> v >> k;
		k++;
		
		int ans = oo;
		for(int i = 0; i <= k; i++)
			ans = min(ans, d[v][i]);
		
		if(ans == oo)
			cout << "=[" << endl;
		else
			cout << "=] " << ans << endl;
	}

	return 0;
}