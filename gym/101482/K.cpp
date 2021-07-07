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

struct fenwick
{
	int n;
	vector<int> f;
	fenwick(int n) : n(n + 1), f(n + 5) {}

	int query(int p)
	{
		++p;
		int cur = 0, r = 0;

		for (int i = p-1; i > 0; i -= i & -i)
			r -= f[i];

		for (int i = 25; i >= 0; --i)
		{
			if (cur + (1<<i) > n) continue;
			cur += 1<<i;

			r += f[cur];
			if (r > 0 && cur >= p)
				r -= f[cur], cur -= 1<<i;
		}

		++cur;
		if (cur >= n) return -1;
		return cur - 1;
	}

	void update(int p, int v)
	{
		//debug(p, v)
		++p;
		for (; p <= n; p += p & -p)
			f[p] += v;
	}
};

int main()
{
	#ifdef DGC
		freopen("a.in", "r", stdin);
		//freopen("b.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, s, t;
	cin >> n >> s >> t;

	fenwick f(s);

	vector<int> p(n);
	for (auto &i : p)
		cin >> i;

	sort(p.begin(), p.end());

	vector<ll> cost(s);
	for (int i = 0; i < n; ++i)
	{
		//debug("on", i)
		for (auto j : p)
			f.update(j, +1);

		int cur = p[i]; ll x = 0;

		for (int it = n; it > 0; --it)
		{
			int go = f.query(cur);
			if (go == -1) go = f.query(0);

			if (go >= cur)
				x += go - cur;
			else
				x += s - cur + go;

			x += t;
			cur = go;
			f.update(cur, -1);

			cur = (cur + t) % s;
		}

		//debug(p[i], x)
		cost[p[i]] = x;
	}

	vector<ll> dp(s, -1);
	for (int i = 0; i < n; ++i)
		dp[p[i]] = p[i];

	if (dp.back() == -1)
		dp.back() = p[0];

	for (int i = s-2; i >= 0; --i)
	{
		if (dp[i] == -1)
			dp[i] = dp[i+1];
	}

	//debug(dp)

	for (int i = 0; i < s; ++i)
	{
		ll x = 0;
		if (dp[i] >= i)
			x = dp[i] - i;
		else
			x = s - i + dp[i];

		dp[i] = x + cost[dp[i]];
	}

	//debug(cost)
	//debug(dp)

	cout << *min_element(dp.begin(), dp.end()) << "\n";
	cout << *max_element(dp.begin(), dp.end()) << "\n";
	ll x = accumulate(dp.begin(), dp.end(), 0LL);
	ll y = s;
	ll g = __gcd(x, y);
	x /= g;
	y /= g;
	cout << x << "/" << y << "\n";

	return 0;
}