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
	vector<vector<ll>> a(1);

	ll x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		a.back().push_back(x);
		if (~x>>7&1) a.push_back({});
	}

	a.pop_back();
	for (auto &i : a)
	{
		vector<int> b;
		for (auto j : i)
			for (int k = 0; k < 7; ++k)
				b.push_back(j>>k&1);

		int sgn = +1;
		if (b[0]) sgn = -1;

		reverse(b.begin(), b.end());
		b.pop_back();
		ll ans = 0;
		for (auto j : b)
			ans = 2*ans + j;

		if (sgn == -1) ++ans;
		cout << ans * sgn << "\n";
	}

	return 0;
}