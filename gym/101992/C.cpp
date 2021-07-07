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

	freopen("transform.in", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m), c(n);
		for (auto &i : a) cin >> i;
		for (auto &i : b) cin >> i;
		for (auto &i : c) cin >> i;

		vector<int> id = a;
		for (auto i : b) id.push_back(i);
		sort(id.begin(), id.end());
		id.erase(unique(id.begin(), id.end()), id.end());
		for (auto &i : a) i = lower_bound(id.begin(), id.end(), i) - id.begin();
		for (auto &i : b) i = lower_bound(id.begin(), id.end(), i) - id.begin();

		vector<int> mp(id.size()), f(id.size());
		for (auto i : b) f[i]++;

		const ll inf = numeric_limits<ll>::max();
		vector<vector<ll>> dp(n+1, vector<ll>(m+1, inf));
		dp[0][0] = 0;

		//debug(a)
		//debug(b)

		for (int j = 0; j <= m; ++j)
		{
			for (int i = 0; i < n; ++i)
				if (dp[i][j] != inf)
				{
					bool e = !mp[a[i]] || !f[a[i]];

					if (j < m && a[i] == b[j])
						dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);

					if (e)
						dp[i+1][j] = min(dp[i+1][j], dp[i][j] + c[i]);
				}
			if (j < m) f[b[j]]--;
			if (j < m) mp[b[j]]++;
		}

		/*for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= m; ++j)
				debug(i, j, dp[i][j])*/

		if (dp[n][m] == inf)
			cout << "No\n";
		else
			cout << dp[n][m] << "\n";
	}

	return 0;
}