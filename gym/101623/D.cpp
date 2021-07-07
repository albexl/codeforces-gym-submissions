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



int main()
{
	#ifdef DGC
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<string> a(n);
	for (auto &i : a) cin >> i;

	int m;
	cin >> m;
	map<string, vector<string>> c, in;
	for (string x, y, z; m--; )
	{
		cin >> x >> y >> z;
		if (z[0] == 'c')
			c[x].push_back(y);
		else
			in[x].push_back(y);
	}

	vector<vector<ll>> dp(2, vector<ll>(n+1));
	dp[0][0] = 1;

	vector<string> ans;
	for (int i = 0; i < n; ++i)
	{
		if (c.count(a[i]))
		{
			for (auto j : c[a[i]])
			{
				dp[0][i+1] += dp[0][i];
				dp[1][i+1] += dp[1][i];
				ans.push_back(j);
			}
		}

		if (in.count(a[i]))
		{
			for (auto j : in[a[i]])
			{
				dp[1][i+1] += dp[0][i];
				dp[1][i+1] += dp[1][i];
				ans.push_back(j);
			}
		}
	}

	if (dp[0][n] + dp[1][n] == 1)
	{
		for (auto &i : ans)
			cout << i << " \n"[&i==&ans.back()];
		cout << ((dp[0][n] == 1) ? "correct" : "incorrect") << "\n";
		return 0;
	}

	cout << dp[0][n] << " correct\n";
	cout << dp[1][n] << " incorrect\n";

	return 0;
}