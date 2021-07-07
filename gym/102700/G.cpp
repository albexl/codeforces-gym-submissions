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

const ll mod = 1e9 + 7;

ll mod_exp(ll a, ll b){
	if(b == 0)
		return 1ll;
	if(b % 2 == 0){
		ll t = mod_exp(a, b / 2ll) % mod;
		return t * t % mod;
	}
	return a * mod_exp(a, b - 1) % mod;
}

ll inv(ll x){
	return mod_exp(x, mod - 2) % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);


	int n, m;
	cin >> n >> m;

	vector<ll> f(n + 5);
	f[0] = 1ll;
	for(int i = 1; i <= n; i++)
		f[i] = (f[i - 1] * 1ll * i) % mod;

	ll ans = f[n];
	f = vector<ll>(m + 5);
	f[0] = 1ll;
	for(int i = 1; i <= m; i++)
		f[i] = (f[i - 1] * 2ll) % mod;

	ans = (ans * inv(f[m])) % mod;
	cout << ans << endl;

	return 0;
}