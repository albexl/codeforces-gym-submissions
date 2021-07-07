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
typedef complex<ll> point;
#define F first
#define S second
#define endl '\n'

#define int ll

signed main()
{
	//#ifdef DGC
		freopen("little.in", "r", stdin);
		freopen("little.out", "w", stdout);
	//#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	ll n = 12;
	cin >> n;

	for (int i = 0; i < 63; ++i)
		if ((1LL << i) == n)
		{
			cout << "-1\n";
			return 0;
		}

	const int N = 1e7 + 5;
	vector<int> pr(1, 2);
	vector<int> pos(N + 5);
	for (ll i = 3; i <= N; i += 2)
	    if (!pos[i])
	    {
	    	pr.push_back(i);
	        for (ll j = i * i; j <= N; j += 2 * i)
	            pos[j] = i;
	    }

	ll x = n;
	vector<pair<int, int>> f;
	for (auto i : pr)
	{
		if (x % i == 0)
		{
			int cnt = 0;
			while (x % i == 0)
			{
				++cnt;
				x /= i;
			}

			f.push_back({ i, cnt });
		}
	}

	if (x > 1)
	{
		ll r = sqrtl(x), r2 = -1;
		for (int i = -50; i <= 50; ++i)
			if (r + i > 0)
			{
				if ((r+i) * (r+i) > x) break;
				if ((r+i) * (r+i) == x)
				{
					r += i;
					r2 = r;
					break;
				}
			}

		if (r2 != -1)
		{
			f.push_back({ r2, 2 });
			x = 1;
		}
	}

	if (x > 1)
	{
		f.push_back({ x, 1 });
	}

	int sz = f.size();
	vector<ll> d;
	function<void(ll, int)> go = [&](ll cur, int p)
	{
		if (p == sz)
		{
			d.push_back(cur);
			return;
		}
		for (int i = 0, z = 1; i <= f[p].S; ++i)
		{
			go(cur * z, p + 1);
			z *= f[p].F;
		}
	};

	go(1, 0);

	vector<vector<int>> ans;
	for (auto i : d)
	{
		if (i == 1) continue;

		int cnt1 = 0;
		int cnt2 = 0;
		x = n;

		debug(x, i, i+1)

		while (x % i == 0) x /= i, ++cnt1;
		while (x % (i+1) == 0) x /= (i+1), ++cnt2;

		if (x == 1)
		{
			ans.emplace_back();
			while (cnt1--) ans.back().push_back(i);
			while (cnt2--) ans.back().push_back(i+1);
		}
	}

	cout << ans.size() << "\n";
	for (auto &i : ans)
	{
		cout << i.size();
		for (auto &j : i)
			cout << " " << j;
		cout << "\n";
	}

	return 0;
}