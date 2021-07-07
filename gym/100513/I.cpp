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



int main()
{
	#ifdef DGC
		//freopen("a.in", "r", stdin);
		//freopen("b.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	sort(a.begin(), a.end());

	int x = a.back();
	a.pop_back();

	int ans = 1;
	for (auto i : a)
	{
		if (i <= x)
			x -= i, ++ans;
	}

	cout << ans << "\n";

	return 0;
}