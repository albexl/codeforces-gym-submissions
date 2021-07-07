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
// typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// template<typename T>
// static T randint(T lo, T hi){
// 	return uniform_int_distribution<T>(lo, hi)(rng);
// }

vector<bool> bfs(vector<vector<int>> &g, int s){
	queue<int> Q;
	Q.push(s);
	vector<bool> seen(g.size());
	seen[s] = true;
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		for(auto &v : g[u])
			if(!seen[v]){
				seen[v] = true;
				Q.push(v);
			}
	}
	return seen;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	int n, m, s;
	cin >> n >> m >> s;

	vector<vector<int>> g(n + 1), gr(n + 1);
	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		g[a].push_back(b);
		gr[b].push_back(a);
	}

	auto f1 = bfs(g, s);
	auto f2 = bfs(gr, s);

	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += !f1[i];
		ans += !f2[i];
	}

	cout << ans << endl;

	return 0;
}