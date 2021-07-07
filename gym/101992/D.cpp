#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715;
#endif
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second



int main()
{
	#ifdef DGC
		//freopen("b.out", "w", stdout);
	#endif

	freopen("lcm.in", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		const ll N = 100000, mod = 1e9 + 7;

		auto Pow = [&](ll a, ll b)
		{
			ll x = 1;
			for (; b > 0; b >>= 1)
			{
				if (b&1) x = x * a % mod;
				a = a * a % mod;
			}
			return x;
		};

		vector<ll> dp(N+1);
		vector<vector<int>> g(N+1);
		for (int i = 0, x; i < n; ++i)
		{
			cin >> x;
			vector<int> f;
			for (int j = 1; j*j <= x; ++j)
				if (x % j == 0)
				{
					f.push_back(j);
					if (j*j != x)
						f.push_back(x / j);
				}

			for (auto j : f)
				g[j].push_back(x);
		}

		for (int i = 1; i <= N; ++i)
		{
			ll s = 0;
			for (auto u : g[i]) s += u;
			for (auto u : g[i]) dp[i] += (s) % mod * u % mod, dp[i] %= mod;
		}

		for (int i = N; i > 0; --i)
			for (int j = 2*i; j <= N; j += i)
				dp[i] += mod - dp[j], dp[i] %= mod;

		ll ans = 0;
		for (int i = 1; i <= N; ++i)
			ans += dp[i] * Pow(i, mod-2), ans %= mod;

		cout << ans << "\n";
	}

	return 0;
}