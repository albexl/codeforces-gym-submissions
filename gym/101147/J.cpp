#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, ll> pii;

const int maxn = 5e5 + 5;

vector<pii> g[maxn];
ll c[maxn], d[maxn], ans[maxn];

priority_queue<ll> pq[maxn];

void dfs(int u, int p){
	for(auto &v : g[u]){
		if(v.first != p){
			d[v.first] = d[u] + v.second;
			dfs(v.first, u);
		}
	}
}

void solve(int u, int p){

	for(auto &e : g[u]){
		int v = e.first;

		if(v == p)
			continue;

		solve(v, u);

		if(pq[v].size() > pq[u].size())
			swap(pq[v], pq[u]);

		auto &child = pq[v];

		while(!pq[v].empty()){
			pq[u].push(pq[v].top());
			pq[v].pop();
		}
	}

	while(!pq[u].empty() && pq[u].top() > d[u])
		pq[u].pop();

	ans[u] = pq[u].size();
	pq[u].push(d[u] - c[u]);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	freopen("car.in", "r", stdin);

	int tc;
	cin >> tc;

	while(tc--){

		int n;
		cin >> n;

		for(int i = 1; i <= n; i++){
			g[i].clear();
			while(!pq[i].empty())
				pq[i].pop();
			cin >> c[i];
			d[i] = 0;
		}

		for(int i = 1; i < n; i++){
			int a, b;
			ll c;
			cin >> a >> b >> c;
			g[a].push_back({b, c});
			g[b].push_back({a, c});
		}

		dfs(1, 0);
		solve(1, 0);

		for(int i = 1; i <= n; i++)
			cout << ans[i] << " \n"[i == n];
	}
 
	return 0;
}