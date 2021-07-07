#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, ll> tri;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

const int maxn = 1e5 + 5;

struct segment_tree{

	vector<ll> st;

	segment_tree(int n) : st(4 * n){ }

	void update(int node, int b, int e, int pos, ll x){
		if(b == e)
			st[node] += x;
		else{
			int m = (b + e) >> 1;
			int l = node << 1;
			int r = l | 1;

			if(pos <= m)
				update(l, b, m, pos, x);
			else
				update(r, m + 1, e, pos, x);

			st[node] = st[l] + st[r];
		}
	}

	ll query(int node, int b, int e, int i, int j){
		if(b >= i && e <= j)
			return st[node];

		if(b > j || e < i)
			return 0ll;

		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;

		ll L = query(l, b, m, i, j);
		ll R = query(r, m + 1, e, i, j);

		return L + R;
	}
};


int lo[maxn], hi[maxn], n, t, q;
vector<int> g[maxn];

void dfs(int u, int p){
	lo[u] = t++;
	for(auto &v : g[u])
		if(v != p)
			dfs(v, u);
	hi[u] = t - 1;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("perimetric_chapter_1_input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int test;
	cin >> test;

	while(test--){
		cin >> n >> q;

		t = 1;
		for(int i = 1; i <= n; i++){
			g[i].clear();
			lo[i] = hi[i] = 0;
		}

		for(int i = 1, a, b; i < n; i++){
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);

			// cerr << a << " --- " << b << endl;
		}

		segment_tree st1(n), st2(n);
		dfs(1, 0);

		// cerr << "after dfs" << endl;

		while(q--){
			int ty, x, y;
			cin >> x >> y >> ty;

			// cerr << "execute" << endl;

			if(ty == 0){
				if(lo[x] > lo[y])
					swap(x, y);

				ll v1 = st1.query(1, 1, n, lo[y], hi[y]);
				ll v2 = st2.query(1, 1, n, lo[y], hi[y]);

				// cerr << v1 << " " << v2 << endl;

				cout << abs(v1 - v2) << endl;
			}
			else{
				ll val = 1ll * ty;
				// cerr << "update " << val << endl;
				st1.update(1, 1, n, lo[x], val);
				st2.update(1, 1, n, lo[y], val);
			}
		}
	}

	

	return 0;
}