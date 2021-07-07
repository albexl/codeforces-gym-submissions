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

vector<ll> dp[14];

int main()
{
	#ifdef DGC
		//freopen("a.in", "r", stdin);
		//freopen("b.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n; ll l;
	cin >> n >> l;
	//n = 14, l = 1;
	vector<vector<ll>> d(n, vector<ll>(n));
	for (auto &i : d)
		for (auto &j : i)
			cin >> j;
			//j = 0;

	if (n < 5)
	{
		vector<int> id(n);
		iota(id.begin(), id.end(), 0);

		do
		{
			ll x = 0;
			for (int i = 1; i < n; ++i)
				x += d[id[i-1]][id[i]];

			x += d[id.back()][id[0]];

			if (x == l)
			{
				cout << "possible\n";
				return 0;
			}

		} while (next_permutation(id.begin(), id.end()));

		cout << "impossible\n";
		return 0;
	}

	int s1 = n/2, s2 = n - s1;

	vector<int> id(s2);
	iota(id.begin(), id.end(), 0);

	vector<int> id2(s1);
	iota(id2.begin(), id2.end(), 0);

	vector<vector<int>> f(2);

	for (int m = 1; m < 1<<n; ++m)
		if (__builtin_popcount(m) == s2)
		{
			f[0].clear();
			f[1].clear();
			for (int i = 0; i < n; ++i)
				f[m>>i&1].push_back(i);

			if (f[0][0] != 0) continue;

			for (int i = 0; i < s2; ++i)
				dp[i].clear();

			do
			{
				ll x = 0;
				for (int i = 1; i < s2; ++i)
					x += d[f[1][id[i-1]]][f[1][id[i]]];

				x += d[f[1][id.back()]][0];
				dp[id[0]].push_back(x);

			} while (next_permutation(id.begin(), id.end()));

			for (int i = 0; i < s2; ++i)
				sort(dp[i].begin(), dp[i].end());

			do
			{
				ll x = 0;
				for (int i = 1; i < s1; ++i)
					x += d[f[0][id2[i-1]]][f[0][id2[i]]];

				for (int i = 0; i < s2; ++i)
				{
					ll y = x + d[f[0][id2.back()]][f[1][id[i]]];
					auto it = lower_bound(dp[i].begin(), dp[i].end(), l - y);
					if (it != dp[i].end() && *it == l - y)
					{
						cout << "possible\n";
						return 0;
					}
				}

			} while (next_permutation(id2.begin() + 1, id2.end()));
		}

	cout << "impossible\n";
	//cout << clock() * 1000 / CLOCKS_PER_SEC;

	return 0;
}