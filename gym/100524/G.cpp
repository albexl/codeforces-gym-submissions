#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> graph;

ll fast_pow(ll a, ll b, ll mod)
{
	if(!b) return 1;
	ll l = fast_pow(a, b >> 1, mod);
	l = l * l % mod;
	if(b & 1) l = a * l % mod;
	return l;
}

const ll maxn = 105, mod = 242121643;
vector<ll> ans(maxn, -1);
vector<ll> fac(maxn), ifac(maxn), p2(maxn);

ll bin(int n, int k, ll mod)
{
	if(k > n || n < 0) return 0;
	return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	ifac[0] = p2[0] = fac[0] = 1;
	for(int i = 1; i < (int)fac.size(); ++i)
	{
		fac[i] = fac[i - 1] * i % mod;
		p2[i] = p2[i - 1] * 2 % mod;
		ifac[i] = fast_pow(fac[i], mod - 2, mod);
	}

	int n, k;
	while(cin >> n >> k && !(n == 0 && k == 0))
	{
		int c1 = 0;
		for(int i = 0, x; i < n; ++i)
			cin >> x, c1 += x == 1;

		ll ans = 0;
		for(int i = 1; i <= min(c1, k); i += 2)
			ans = (ans + bin(c1, i, mod) * bin(n - c1, k - i, mod) % mod) % mod;

		cout << ans << endl;
	}

	return 0;
}