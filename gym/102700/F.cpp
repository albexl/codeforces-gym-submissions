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
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

const int oo = 1e9;

vector<vector<int>> dijkstra(int s, int k, int n, vector<vector<pii>> &g){
	vector<vector<int>> d(n + 1, vector<int>(k + 1, oo));
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

	d[s][k] = 0;
	pq.push({0, {s, k}});

	while(!pq.empty()){
		int u = pq.top().second.first;
		int r = pq.top().second.second;
		int w = pq.top().first;
		pq.pop();

		if(w != d[u][r])
			continue;

		for(auto &e : g[u]){
			int v = e.first;
			int c = e.second;

			if(d[v][r] > d[u][r] + c){
				d[v][r] = d[u][r] + c;
				pq.push({d[v][r], {v, r}});
			}

			if(r > 0){
				if(d[v][r - 1] > d[u][r]){
					d[v][r - 1] = d[u][r];
					pq.push({d[v][r - 1], {v, r - 1}});
				}
			}
		}
	}

	return d;
}

int n, m, a, b, k;
void print(vector<vector<int>> &d){
	for(int i = 0; i < n; i++)
		cout << d[i][0] << " ";
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	cin >> n >> m >> a >> b >> k;

	vector<vector<pii>> g(n), gr(n);

	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		gr[v].push_back({u, w});
	}

	auto dga = dijkstra(a, k, n, g);
	auto dgb = dijkstra(b, k, n, g);
	auto dgra = dijkstra(a, k, n, gr);
	auto dgrb = dijkstra(b, k, n, gr);

	vector<int> sol(n);
	for(int i = 0; i < n; i++){
		int val = oo;
		for(int j = k - 1; j >= 0; j--){
			dga[i][j] = min(dga[i][j], dga[i][j + 1]);
			dgra[i][j] = min(dgra[i][j], dgra[i][j + 1]);
		}

		for(int j = 0; j <= k; j++)
			val = min(val, dga[i][k - j] + dgra[i][j]);
		
		sol[i] += val;
	}

	for(int i = 0; i < n; i++){
		int val = oo;
		for(int j = k - 1; j >= 0; j--){
			dgb[i][j] = min(dgb[i][j], dgb[i][j + 1]);
			dgrb[i][j] = min(dgrb[i][j], dgrb[i][j + 1]);
		}

		for(int j = 0; j <= k; j++)
			val = min(val, dgb[i][k - j] + dgrb[i][j]);
		
		sol[i] += val;
	}


	int ans = oo, node = -1;
	for(int i = 0; i < n; i++){
		if(i != a && i != b && sol[i] < ans){
			ans = sol[i];
			node = i;
		}
	}
	

	if(node == -1)
		cout << ">:(" << endl;
	else
		cout << node << " " << ans << endl;

	return 0;
}