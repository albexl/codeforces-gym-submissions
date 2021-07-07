#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second

#define int ll

signed main()
{
	#ifdef DGC
		//freopen("a.in", "r", stdin);
		//freopen("b.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &i : a) cin >> i;

	int mn = *min_element(a.begin(), a.end());

	set<int> s;
	int cur = 0;

	for (int i = 0; i < k-1; ++i)
		s.insert(i), cur += a[i];

	int ans = 0;
	for (int i = k-1; i < n; ++i)
	{
		s.insert(i);
		cur += a[i];

		if (i-k >= 0)
		{
			s.erase(i-k);
			cur -= a[i-k];
		}

		while (cur >= 0)
		{
			int p = *s.rbegin();
			s.erase(p);

			int d = a[p] - mn;
			int need = cur + 1;

			a[p] -= min(d, need);
			cur -= min(d, need);
			ans += min(d, need);
		}
	}

	cout << ans << '\n';
	for (auto &i : a)
		cout << i << " \n"[&i==&a.back()];

	return 0;
}