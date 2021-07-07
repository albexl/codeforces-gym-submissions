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
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	freopen("foreign.in", "r", stdin);
	freopen("foreign.out", "w", stdout);

	string s;
	cin >> s;

	int n = s.length();
	vector<ll> c(n), w(n);
	for (int i = 0; i < n; ++i)
	{
		c[i] = (s[i] == 'C');
		w[i] = !c[i];

		c[i] *= n-i;
		w[i] *= n-i;
	}

	for (int i = n-2; i >= 0; --i)
	{
		c[i] += c[i+1];
		w[i] += w[i+1];
	}

	debug(c)
	debug(w)

	vector<ld> dp(n+1);
	dp[n-1] = dp[n] = 0.0;

	for (int i = n-2; i >= 0; --i)
	{
		dp[i] = dp[i+1] / (ld)(n-i);
		if (s[i] == 'W') dp[i] += c[i] / (ld)(n-i);
		else dp[i] += w[i] / (ld)(n-i);

		//dp[i] /= (ld)(n-i);

		dp[i] += dp[i+1];
	}

	debug(dp)

	cout.precision(20);
	cout << fixed << dp[0] - dp[1] << "\n";

	return 0;
}