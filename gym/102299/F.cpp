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

	ll a, b;
	cin >> a >> b;

	ll g = __gcd(a, b);
	a /= g;
	b /= g;

	ll ans = 1;
	for (int i = 2; i <= 1e6+5; ++i)
	{
		if (b % i == 0)
		{
			while (b % i == 0) b /= i;
			ans *= i;
		}
	}

	if (b > 3)
	{
		ll r = sqrtl((ld)b);
		for (int i = -100; i <= 100; ++i)
		{
			if (r+i > 0 && (r+i)*(r+i) > b) break;
			if (r+i > 0 && (r+i)*(r+i) == b)
			{
				ans *= (r+i);
				b = 1;
				break;
			}
		}
	}

	ans *= b;
	cout << max(2LL, ans) << "\n";

	return 0;
}