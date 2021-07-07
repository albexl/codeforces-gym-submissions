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

	ll x, y, mn = numeric_limits<ll>::max(), ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		ans += x+y;
		mn = min(mn, x-y);
	}

	cout << ans + mn - (n-1) << "\n";

	return 0;
}