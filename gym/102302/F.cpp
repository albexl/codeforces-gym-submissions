#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second



int main()
{
	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<double> dp(n);
	dp[0] = 1.0;
	for (int i = 1; i < n; ++i)
		dp[i] = dp[i-1] * ((double)n-i)/n;

	double ans = 0;
	for (int i = 0; i < n; ++i)
		ans += (double)1.0/n * (i+1);

	cout.precision(10);
	cout << fixed;
	cout << ans << "\n";

	return 0;
}