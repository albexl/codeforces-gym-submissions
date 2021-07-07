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

const int maxn = 1e6 + 5;

int sz[maxn], pi[maxn], n, m, k;

int root(int x){
	return pi[x] == x ? x : root(pi[x]);
}

void merge(int a, int b){
	a = root(a), b = root(b);
	if(a == b)
		return;

	if(sz[a] > sz[b])
		swap(a, b);

	pi[a] = b;
	sz[b] += sz[a];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	const ll mod = 1e9 + 7;

	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		sz[pi[i] = i] = 1;

	vector<pair<int, pii>> edges(m);
	vector<int> h(k);
	
	for(int i = 0, a, b, c; i < m; i++){
		cin >> a >> b >> c;
		edges[i] = {c, {a, b}};
	}

	for(int i = 0; i < k; i++)
		cin >> h[i];
	
	sort(edges.begin(), edges.end());
	sort(h.begin(), h.end());

	ll ans = 1, cur = 1ll * n * (n - 1) % mod;

	for(int i = 0, j = 0; i < k; i++){
		while(j < m && edges[j].first <= h[i]){
			int a = root(edges[j].second.first);
			int b = root(edges[j].second.second);

			if(a != b){
				ll s1 = 1ll * sz[a], s2 = 1ll * sz[b];
				cur = (cur - 2ll * s1 * s2 % mod + mod) % mod;
				merge(a, b);
			}

			j++;
		}
		
		ans = ans * cur % mod;
	}


	cout << ans << endl;

	return 0;
}