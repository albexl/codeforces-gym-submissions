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

	int cnt = 0;
	for (int i = 2; i <= 1000000; ++i)
		if (n % i == 0)
		{
			int c = 0;
			while (n % i == 0) n /= i, ++c;
			if (c > 1)
			{
				cout << "NO\n";
				return 0;
			}
			++cnt;
		}

	if (n > 1)
		++cnt;

	if (cnt == 3)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}