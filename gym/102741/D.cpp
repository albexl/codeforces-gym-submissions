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

const ll mod = 1e9 + 7;

struct union_find
{
	vector<int> p;

	union_find(int n) : p(n, -1) {}

	bool join(int u, int v)
	{
		if ((u = root(u)) == (v = root(v)))
			return false;
		if (p[u] > p[v])
			swap(u, v);
		p[u] += p[v];
		p[v] = u;
		return true;
	}

	int root(int u)
	{
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	int n, p, m;
	cin >> n >> p >> m;

	union_find ds(n);

	for(int i = 1; i + p - 1 <= n; i++){
		int lo = i, hi = i + p - 1;
		while(lo <= hi){
			ds.join(lo - 1, hi - 1);
			lo++, hi--;
		}
	}

	int cnt = 0;
	for(int i = 0; i < n; i++)
		if(ds.root(i) == i)
			cnt++;

	ll ans = 1ll;
	for(int i = 0; i < cnt; i++)
		ans = (ans * 1ll * m) % mod;

	cout << ans << endl;

	return 0;
}