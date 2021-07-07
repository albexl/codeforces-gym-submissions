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
// typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// template<typename T>
// static T randint(T lo, T hi){
// 	return uniform_int_distribution<T>(lo, hi)(rng);
// }



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<ll> d(n);
	for(int i = 0; i < n; i++)
		cin >> d[i];

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	for(int i = 0; i < n; i++)
		pq.push({d[i], i});

	vector<vector<pii>> g(n);
	for(int i = 0; i < m; i++){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		g[a].push_back({c, b});
	}

	while(!pq.empty()){
		int u;
		ll w;
		tie(w, u) = pq.top();pq.pop();

		if(d[u] != w)
			continue;

		for(auto &e : g[u]){
			int v;
			ll c;
			tie(c, v) = e;

			if(d[v] > d[u] + c){
				d[v] = d[u] + c;
				pq.push({d[v], v});
			}
		}
	}

	ll ans = 0;
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		ans += x * d[i];
	}

	cout << ans << endl;

	return 0;
}