#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second

const ll mod = 1e9+7;

ll Pow(ll a, ll b)
{
	ll x = 1;
	for (; b > 0; b >>= 1)
	{
		if (b & 1) x = x * a % mod;
		a = a * a % mod;
	}
	return x;
}

int main()
{
	//#ifdef DGC
	    freopen("rooks.in", "r", stdin);
		//freopen("b.out", "w", stdout);
	//#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	vector<ll> fac(1005), ifac(1005);
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < 1005; ++i)
	{
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = Pow(fac[i], mod-2);
	}

	auto comb = [&](ll n, ll k)
	{
		return fac[n] * ifac[k] % mod * ifac[n-k] % mod;
	};

	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test)
	{
		int n, m, K;
		cin >> n >> m >> K;

		set<int> x, y;
		for (int i = 0, a, b; i < K; ++i)
		{
			cin >> a >> b;
			x.insert(a);
			y.insert(b);
		}

		if (x.size() > y.size())
		{
			swap(x, y);
			swap(n, m);
		}

		int i = x.size();
		int k = y.size();

		//debug(i, k, n, m)

		ll ans = 0;
		for (int v = 0; v <= i; ++v)
		{
			//debug(v, comb(i, v) * Pow(n - v, k))
			ans += ((v&1) ? -1 : +1) * comb(i, v) * Pow(n - v, k) % mod;
			ans %= mod;
			ans += mod;
			ans %= mod;
		}

		cout << "Case " << test << ": " << k << " " << ans << "\n";
	}

	return 0;
}