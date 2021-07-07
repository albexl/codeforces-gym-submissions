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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (auto &i : a) cin >> i.F >> i.S;

	sort(a.begin(), a.end(), [](const pair<int, int> &x, const pair<int, int> &y){ return x.S > y.S; });

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ordered_set<pair<int, int>> s;

		for (int j = 0; j < n; ++j)
			if (a[j].S <= a[i].S)
				s.insert({ a[j].F, a[j].S });

		int p = n-1;
		for (int j = n-1; a[j].S < a[i].S; --j)
		{
			while (a[p].S < a[j].S)
			{
				s.erase({ a[p].F, a[p].S });
				--p;
			}

			if (a[j].F > a[i].F && s.find({ a[j].F, a[i].S }) != s.end() && s.find({ a[i].F, a[j].S }) != s.end())
			{
				ans += s.order_of_key({ a[j].F, 1<<30 }) - s.order_of_key({ a[i].F, -1 }) == 4;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}