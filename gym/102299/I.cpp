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
	vector<pair<ll, ll>> a(n);
	for (auto &i : a) cin >> i.F >> i.S, i.S *= -1;

	sort(a.begin(), a.end(), [](const pair<ll, ll> &x, const pair<ll, ll> &y){ return x.S > y.S; });

	ll ans = numeric_limits<ll>::min();
	ll s = 0;
	for (auto i : a)
	{
		s += i.F;
		ans = max(ans, s + i.S);
	}

	cout << ans << "\n";

	return 0;
}