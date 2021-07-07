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
	freopen("digits.in", "r", stdin);
	freopen("digits.out", "w", stdout);

	ios_base::sync_with_stdio(0), cin.tie(0);

	vector<vector<ll>> num(2000);

	for (int i = 1; i < 3000000; ++i)
	{
		string s = to_string(i);
		int c = 0;
		for (auto i : s)
			c += i-'0';

		num[c].push_back(i);
	}

	for (auto &i : num)
	{
		ll last = 0;
		for (auto &j : i)
			j += last, last = j;
	}

	int n;
	cin >> n;
	ll ans = 1LL<<60;
	for (auto &i : num)
		if (i.size() >= n)
			ans = min(ans, i[n-1]);

	cout << ans << "\n";

	return 0;
}