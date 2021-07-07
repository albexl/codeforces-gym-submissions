#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<int> point;
#define F first
#define S second

ll dp[2][505][505];

struct info
{
	ll g, t, g2, t2;

	bool operator<(const info &f) const
	{
		return g < f.g;
	}
};

int main()
{
	#ifdef NeverBeRed
		//freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	ll n, s1, s2;
	cin >> n >> s1 >> s2;
	vector<info> a(n);
	for (auto &i : a) cin >> i.g >> i.t >> i.g2 >> i.t2;

	sort(a.begin(), a.end());

	memset(dp[0], 63, sizeof dp[0]);
	const ll inf = dp[0][0][0];
	dp[0][0][0] = 0;

	for (ll k = 0; k < n; ++k)
	{
		auto &cur = dp[k&1];
		auto &ncur = dp[~k&1];
		memset(ncur, 63, sizeof ncur);

		for (ll i = 0, ni, nj; i <= s1; ++i)
			for (ll j = 0; j <= s2; ++j)
				if (cur[i][j] != inf)
				{
						ncur[i][j] = min(ncur[i][j], cur[i][j]);

						if (i < s1)
						{
							ni = min(s1, i + a[k].g), nj = min(s2, j + max(0LL, i + a[k].g - s1));
							ncur[ni][nj] = min(ncur[ni][nj], cur[i][j] + a[k].t);
						}

						ni = i, nj = min(s2, j + a[k].g2);
						ncur[ni][nj] = min(ncur[ni][nj], cur[i][j] + a[k].t2);
				}
	}

	ll ans = dp[n&1][s1][s2];
	if (ans == inf) ans = -1;
	cout << ans << "\n";

	return 0;
}