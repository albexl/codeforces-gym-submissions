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

const ll oo = 1e16;
const int maxn = 1e5 + 5;

struct segment_tree{
	
	vector<ll> st, lazy;
	
	segment_tree(int n) : st(4 * n), lazy(4 * n){ }
	
	void add_lazy(int node, int b, int e, ll x){
		lazy[node] += x;
		st[node] += 1ll * x * (e - b + 1);
	}
	
	void push(int node, int b, int e){
		if(!lazy[node] || b == e)
			return;
		
		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;
		
		add_lazy(l, b, m, lazy[node]);
		add_lazy(r, m + 1, e, lazy[node]);
		
		lazy[node] = 0;
	}
	
	ll query(int node, int b, int e, int i, int j){
		if(b >= i && e <= j)
			return st[node];
		if(b > j || e < i)
			return 0;
		
		push(node, b, e);
		
		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;
		
		ll L = query(l, b, m, i, j);
		ll R = query(r, m + 1, e, i, j);
		
		return L + R;
	}
	
	void update(int node, int b, int e, int i, int j, ll x){
		if(b >= i && e <= j){
			add_lazy(node, b, e, x);
			return;
		}
		
		if(b > j || e < i)
			return;
		
		push(node, b, e);
		
		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;
		
		update(l, b, m, i, j, x);
		update(r, m + 1, e, i, j, x);
		
		st[node] = st[l] + st[r];
	}
	
};


vector<pair<int, ll>> g[maxn];
ll dst[maxn], A[maxn], B[maxn], T[maxn], dp_down[maxn], dp_up[maxn], sum[maxn], total = 0;
int lo[maxn], hi[maxn], inv[maxn], t = 1, n;

void dfs1(int u, int p){
	
	for(auto &e : g[u]){
		int v = e.first;
		ll c = e.second;
		if(v != p){
			dfs1(v, u);
			dp_down[u] += dp_down[v];
			dp_down[u] += sum[v] * c;
			sum[u] += sum[v];
		}
	}
	sum[u] += T[u];
}

void dfs2(int u, int p, ll w){
	if(p){
		ll x = dp_up[p] + dp_down[p];
		x -= sum[u] * w;
		x -= dp_down[u];
		dp_up[u] = x + (total - sum[u]) * w;
	}
	
	for(auto &e : g[u]){
		int v = e.first;
		ll c = e.second;
		
		if(v != p){
			dfs2(v, u, c);
		}
	}
}

void dfs(int u, int p){
	
	lo[u] = t;
	inv[t] = u;
	t++;
	
	for(auto &e : g[u]){
		int v = e.first;
		ll c = e.second;
		
		if(v != p){
			dst[v] = dst[u] + c;
			dfs(v, u);
		}
	}
	
	hi[u] = t - 1;
}

void solve(int u, int p, segment_tree &st){
	
	A[u] = st.query(1, 1, n, 1, n) * T[u];
	
	for(auto &e : g[u]){
		int v = e.first;
		ll c = e.second;
		
		if(v != p){
			st.update(1, 1, n, 1, n, c);
			st.update(1, 1, n, lo[v], hi[v], -2ll * c);
			
			solve(v, u, st);
			
			st.update(1, 1, n, lo[v], hi[v], 2ll * c);
			st.update(1, 1, n, 1, n, -c);
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> T[i];
		total += T[i];
	}
		
	for(int i = 1; i < n; ++i){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	
	segment_tree st(n);
	dfs(1, 0);

	for(int i = 1; i <= n; i++)
		st.update(1, 1, n, i, i, dst[i]);

	solve(1, 0, st);
	
	//cerr << "here" << endl;
	dfs1(1, 0);
	//cerr << "here" << endl;
	dfs2(1, 0, 0);
	
	for(int i = 1; i <= n; i++)
		cout << A[i] + dp_down[i] + dp_up[i] << endl;

	return 0;
}