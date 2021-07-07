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

	// c people, t per second
	int n, c, t;
	cin >> n >> c >> t;

	vector<int> a(n);
	for (auto &i : a) cin >> i;

	int l = 1, r = 1e9+5;
	while (l < r)
	{
		int m = (l+r) >> 1;

		int eat = min((ll)m * t, (ll)1e9+5);

		bool ok = true;
		for (auto i : a)
		{
			ok &= i <= eat;
		}

		int cur = 0, need = 1;
		if (ok)
		{
			for (auto i : a)
			{
				if (cur + i > eat)
				{
					++need;
					cur = i;
				}
				else
					cur += i;
			}
		}

		if (ok && need <= c)
			r = m;
		else
			l = m+1;
	}

	cout << l << "\n";

	return 0;
}