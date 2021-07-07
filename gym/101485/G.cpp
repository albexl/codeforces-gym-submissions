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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
	#ifdef DGC
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> a(3, vector<int>(n));
	for (auto &i : a)
		for (auto &j : i)
			cin >> j, --j;

	ll ans = 0;

	auto solve = [&](vector<int> x, vector<int> y)
	{
		debug(x, y)
		vector<int> where(n);
		for (auto &i : y)
			where[i] = &i-&y[0];

		for (auto &i : x)
			i = where[i];

		ll ret = 0;
		ordered_set<int> s;
		for (int i = n-1; i >= 0; --i)
		{
			ret += s.order_of_key(x[i]);
			s.insert(x[i]);
		}

		debug(ret)
		return ret;
	};

	ans += solve(a[0], a[1]);
	ans += solve(a[0], a[2]);
	ans += solve(a[1], a[2]);

	ans = n * ((ll)n-1) / 2 - ans / 2;
	cout << ans << "\n";

	return 0;
}