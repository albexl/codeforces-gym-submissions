#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e4 + 5;
const ll mod = 1e9 + 7;

ll fact[maxn];

ll mod_exp(ll a, ll b){
	if(b == 0) return 1ll;
	if(b % 2 == 0){
		ll t = mod_exp(a, b >> 1ll);
		return t * t % mod;
	}
	return a * mod_exp(a, b - 1) % mod;
}

ll inv(ll x){
	return mod_exp(x, mod - 2) % mod;
}

ll n_k(ll n, ll k){
	if(k > n) return 0;
	ll num = fact[n];
	ll den = fact[k] * fact[n - k] % mod;
	return num * inv(den) % mod;
}

ll solve(ll f, ll cnt, ll k){

	ll q = k / f;
	ll r = k - q * f;

	if(r == 0) return n_k(cnt, q) % mod;

	ll ans = n_k(cnt, q) * (cnt - q) % mod * n_k(f, r) % mod;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fact[0] = 1ll;
	for(int i = 1; i < maxn; i++)
		fact[i] = 1ll * i * fact[i - 1] % mod;

	ll n, m, k;
	cin >> n >> m >> k;

	vector<ll> f(m);
	for(int i = 0, x; i < n; i++){
		cin >> x;
		f[x - 1]++;
	}

	vector<ll> c(n + 1);

	for(int i = 0; i < m; i++)
		c[f[i]]++;

	for(int i = 1; i <= n; i++){
		if(1ll * c[i] * i >= k){
			cout << n_k(1ll * c[i] * i, k) << endl;
//			cout << c[i] * i << " " << k << endl;
			return 0;
		}
		k -= 1ll * c[i] * i;
	}

	cout << 1 << endl;

	return 0;
}