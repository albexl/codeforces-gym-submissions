#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second

struct info
{
	ll a, b;
};

int main()
{
	#ifdef DGC
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	freopen("expect.in", "r", stdin);
	freopen("expect.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	vector<info> a(n);
	char ch;
	for (auto &i : a)
	{
		cin >> ch >> i.a >> i.b;
		if (ch == '+')
			i.b *= -1;
	}

	vector<ll> sb(n); // sum of b
	vector<pair<ll, int>> vp; // val, pos
	for (int i = 0; i < n; ++i)
	{
		sb[i] = a[i].b;
		if (i > 0) sb[i] += sb[i-1];

		if (sb[i] > 0 && (vp.empty() || sb[i] > vp.back().F))
			vp.push_back({ sb[i], i });
	}

	vector<ll> difa(n); // a[i+1]-a[i]
	for (int i = n-2; i >= 0; --i)
		difa[i] = a[i+1].a - a[i].a;

	vector<pair<ll, int>> z(q);
	for (auto &i : z) cin >> i.F, i.S = &i-&z[0];
	sort(z.begin(), z.end());

	vector<ll> ans(q, -2);
	vector<ll> sump(q); // sum on prefix
	vector<ll> sum2p(q); // sum2 on prefix
	//vector<ll> sum3p(q); // sum3 on prefix

	vector<ll> coef(q, 1LL);
	for (int i = q-2; i >= 0; --i)
		coef[i] = coef[i+1] + z[i+1].F-z[i].F;

	debug(coef)

	for (int i = 0; i < n-1; ++i)
	{
		ll x = sb[i];
		auto it = lower_bound(z.begin(), z.end(), make_pair(x, 0));

		if (it != z.begin())
		{
			int pos = prev(it) - z.begin();
			ll init = -z[pos].F + x;

			//sum3p[pos] += difa[i] * (init - 1);
			sum2p[pos] += difa[i];
			sump[pos] += difa[i] * (init - 1);
			sump[pos] -= (coef[pos] - 1) * difa[i];
		}
	}

	debug(sum2p)
	debug(sump)

	for (int i = q-2; i >= 0; --i)
	{
		sum2p[i] += sum2p[i+1];
		sump[i] += sump[i+1];
	}

	debug(vp)

	for (auto &temp : z)
	{
		ll init = -temp.F;
		int pos = temp.S;
		int pos2 = &temp-&z[0];

		if (sb[n-1] + init > 0)
		{
			ans[pos] = -1;
			continue;
		}

		/*auto it = lower_bound(vp.begin(), vp.end(), make_pair(-init, 1<<30));
		if (it == vp.end())
		{
			ans[pos] = 0;
			continue;
		}*/

		ans[pos] = sum2p[pos2] * coef[pos2] + sump[pos2];
		debug(temp, ans[pos])
	}

	for (auto i : ans)
	{
		if (i == -1)
			cout << "INFINITY\n";
		else
			cout << i << "\n";
	}

	return 0;
}