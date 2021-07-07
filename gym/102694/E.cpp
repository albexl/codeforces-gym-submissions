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

const double oo = logl(1e9);
const double eps = 1e-9;
const int maxn = 3e5 + 5;

struct segment_tree{

	vector<double> st;

	segment_tree(int n) : st(4 * n){ }

	void update(int node, int b, int e, int pos, double x){
		if(b == e)
			st[node] = logl(x);
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

	double query(int node, int b, int e, int i, int j){
		if(b >= i && e <= j)
			return st[node];
		if(b > j || e < i)
			return 0.0;

		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;

		double L = query(l, b, m, i, j);
		double R = query(r, m + 1, e, i, j);

		return L + R;
	}
};


int lo[maxn], hi[maxn], n, t = 1;
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

	cout << setprecision(10) << fixed;

	cin >> n;
	for(int i = 1, a, b; i < n; i++){
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	segment_tree st(n);
	dfs(1, 0);

	int q;
	cin >> q;

	while(q--){
		int ty, x, y;
		cin >> ty >> x >> y;

		if(ty == 1)
			st.update(1, 1, n, lo[x], 1.0 * y);
		else{
			double v1 = st.query(1, 1, n, lo[x], hi[x]);
			double v2 = st.query(1, 1, n, lo[y], hi[y]);
			double val = v1 - v2;

			if(val + eps > oo)
				cout << "1000000000" << endl;
			else
				cout << expl(val) << endl;
		}

	}

	return 0;
}