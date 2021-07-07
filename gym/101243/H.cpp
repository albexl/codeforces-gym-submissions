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

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	ll x = 1;
	for (int i = 1; i > 0 && n > 0; --i)
	{
		x *= 8;
		--n;
	}

	for (int i = 8; i > 0 && n > 0; --i)
	{
		x *= 9;
		--n;
	}

	cout << x;
	if (n > 0)
		cout << string(n, '0');
	cout << "\n";

	return 0;
}