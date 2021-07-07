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

	vector<ll> ans;
	for (ll i = 1; i*i <= a; ++i)
	{
		if (a % i == 0 && i % b == 0)
			ans.push_back(i);
		if (a % i == 0 && a/i != i && (a/i) % b == 0)
			ans.push_back(a/i);
	}

	sort(ans.begin(), ans.end());
	for (auto &i : ans)
		cout << i << " \n"[&i==&ans.back()];

	return 0;
}