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

vector<string> t = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };

int main()
{
	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	cin >> s;

	int n = s.length();
	vector<ll> dp(n+1);
	dp[0] = 1;

	const ll mod = 1e9+7;
	for (int i = 0; i < n; ++i)
		for (auto j : t)
			if (i+j.length() <= n && s.substr(i, j.length()) == j)
			{
				dp[i+j.length()] += dp[i];
				if (dp[i+j.length()] >= mod)
					dp[i+j.length()] -= mod;
			}

	cout << dp[n] << "\n";

	return 0;
}