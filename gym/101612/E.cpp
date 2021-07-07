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



int main()
{
	//#ifdef DGC
		//freopen("a.txt", "r", stdin);
		freopen("equal.in", "r", stdin);
		freopen("equal.out", "w", stdout);
	//#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	const int N = 1e6 + 5;
	vector<int> pos(N + 5);
	for (ll i = 3; i <= N; i += 2)
	    if (!pos[i])
	    {
	        for (ll j = i * i; j <= N; j += 2 * i)
	            pos[j] = i;
	    }

	for (int i = 4; i <= N; i += 2)
		pos[i] = 2;

	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> n_f;
	vector<pair<int, int>> f_n;
	for (auto &i : a)
	{
		cin >> i;
		++n_f[i];
	}

	for (auto &i : n_f)
		f_n.push_back({ i.S, i.F });

	vector<int> dp(n+5, n);

	sort(f_n.begin(), f_n.end(), greater<pair<int, int>>());
	int cur = 0, cnt = 0;
	for (auto i : f_n)
	{
		++cnt;
		cur += i.F;
		dp[cnt + 1] = min(dp[cnt + 1], n - cur);
	}

	debug(dp)

	int sz;
	vector<int> d;
	vector<pair<int, int>> f;
	function<void(int, int)> go = [&](int cur, int p)
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

	vector<bool> mark(1000005);
	vector<pair<int, int>> gen, ngen;
	while (!n_f.empty())
	{
		auto it = *n_f.rbegin();
		int x = it.F;
		n_f.erase(x);

		if (mark[x])
		{
			ngen.push_back({ it.S, it.F });
			continue;
		}

		gen.push_back({ it.S, it.F });

		f.clear();

		while (pos[x])
		{
			int dv = pos[x];
			int cont = 0;
			while (x % dv == 0)
			{
				++cont;
				x /= dv;
			}

			f.push_back({ dv, cont });
		}

		if (x > 1)
			f.push_back({ x, 1 });

		sz = f.size();
		d.clear();
		go(1, 0);

		for (auto dv : d)
			mark[dv] = true;
	}

	sort(ngen.begin(), ngen.end(), greater<pair<int, int>>());

	debug(gen)
	debug(ngen)

	int sum = 0;
	for (auto i : gen) sum += i.F;

	cnt = gen.size();
	dp[cnt] = min(dp[cnt], n - sum);

	for (auto i : ngen)
	{
		++cnt;
		sum += i.F;
		dp[cnt] = min(dp[cnt], n - sum);
	}

	debug(dp)

	for (int i = 1; i <= n; ++i)
		dp[i] = min(dp[i], dp[i-1]);

	vector<int> ans(n+1, n);
	for (int k = n; k > 0; --k)
		ans[dp[k]] = k;

	for (int i = 1; i < n+1; ++i)
		ans[i] = min(ans[i], ans[i-1]);

	for (auto &i : ans)
		cout << i << " \n"[&i == &ans.back()];

	return 0;
}