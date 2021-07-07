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
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

const int maxn = 201;

int n, m;
bitset<maxn> edge[maxn], reach[maxn];

ll get(int x){
	for(int i = x; i >= 1; i--){
		int y = -1;
		reach[i].reset();

		while(true){
			int v = edge[i]._Find_next(y);
			if(v == maxn)
				break;
			reach[i] |= reach[v];
			y = v;
		}

		reach[i].set(i);
	}

	ll ans = 0;
	for(int i = 1; i <= n; i++)
		ans += reach[i].count();

	ans -= n;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	freopen("settling.in", "r", stdin);
	freopen("settling.out", "w", stdout);
		
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edge[a].set(b);
	}

	cout << get(n) << endl;
	
	int q;
	cin >> q;

	while(q--){
		string op;
		cin >> op;
		
		int u, v;
		cin >> u >> v;

		if(op == "?"){
			if(reach[u].test(v))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else{
			if(op == "+")
				edge[u].set(v);
			else
				edge[u].set(v, 0);
			cout << get(u) << endl;
		}
	}

	return 0;
}