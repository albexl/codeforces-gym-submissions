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

	int n;
	cin >> n;
	while (n--)
	{
		vector<ll> x(3);
		for (auto &i : x) cin >> i;
		ll k;
		cin >> k;

		sort(x.begin(), x.end());

		ll ans = 0;
		do
		{
			for (ll i = 0; i <= 1000; ++i)
				for (ll j = 0; j <= 1000; ++j)
					if (i + j <= k)
					{
						x[0] += i;
						x[1] += j;
						x[2] += k-i-j;
						ans = max(ans, x[0]*x[0] + x[1]*x[1] + x[2]*x[2] + 7 * min({x[0], x[1], x[2]}));
						x[0] -= i;
						x[1] -= j;
						x[2] -= k-i-j;
					}
		} while (next_permutation(x.begin(), x.end()));

		cout << ans << "\n";
	}

	return 0;
}