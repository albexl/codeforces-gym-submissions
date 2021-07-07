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

struct segment_tree{

	vector<int> st;

	segment_tree(int n) :  st(4 * n){ }

	void update(int node, int b, int e, int pos, int x){
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

	int query(int node, int b, int e, int i, int j){
		if(b >= i && e <= j)
			return st[node];

		if(b > j || e < i)
			return 0;

		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;
		
		int L = query(l, b, m, i, j);
		int R = query(r, m + 1, e, i, j);

		return L + R;

	}

};

const int maxn = 1e5 + 5;
segment_tree st(maxn);

struct union_find
{
	vector<int> pi, sz;

	union_find(int n) : pi(n), sz(n) {
		for(int i = 0; i < n; i++)
			sz[pi[i] = i] = 1;
		st.update(1, 1, maxn, 1, n);
	}

	bool join(int u, int v)
	{
		if ((u = root(u)) == (v = root(v)))
			return false;

		if (sz[u] < sz[v])
			swap(u, v);
		
		st.update(1, 1, maxn, sz[u], -1);
		st.update(1, 1, maxn, sz[v], -1);

		sz[u] += sz[v];
		pi[v] = u;

		st.update(1, 1, maxn, sz[u], +1);
		return true;
	}

	int root(int u)
	{
		return pi[u] == u ? u : root(pi[u]);
	}
};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	int n, q;
	cin >> n >> q;

	union_find ds(n);
	while(q--){
		int t;
		cin >> t;

		if(t == 1){
			int x, y;
			cin >> x >> y;
			ds.join(x - 1, y - 1);
		}
		else{
			int val;
			cin >> val;
			cout << st.query(1, 1, maxn, val, maxn) << endl;
		}
	}
	
	return 0;
}