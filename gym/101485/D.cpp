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

ll a, p;
ll dp[1000005];

ll f(int i)
{
	ll &best = dp[i];
	if (best != -1) return best;
	best = 1LL << 60;
	for (int k = 1; k*k <= i; ++k)
	{
		int x = (i+k) / (k+1);
		ll cur = a + p*k + f(x);
		best = min(best, cur);

		int k2 = (i-k + k-1) / k;
		x = (i+k2) / (k2+1);
		assert(x == k);
		cur = a + p*k2 + f(x);
		best = min(best, cur);
	}
	return best;
}

int main()
{
	#ifdef DGC
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	cin >> a >> p;
	memset(dp, -1, sizeof dp);
	dp[0] = dp[1] = 0;
	dp[2] = a + p;
	cout << f(n) << "\n";

	return 0;
}