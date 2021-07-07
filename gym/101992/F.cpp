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

	freopen("mosalah.in", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	ll n, m, x, y;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> x >> y;
		if (y == 0)
		{
			if (m >= n * x)
				cout << "0\n";
			else
				cout << "-1\n";
			continue;
		}

		ll r = n * (x + y) - m;
		cout << max(r, 0LL) << "\n";
	}

	return 0;
}