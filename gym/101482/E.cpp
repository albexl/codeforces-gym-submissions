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

	ld n, p, s, v;
	cin >> n >> p >> s >> v;

	auto f = [&](ld c)
	{
		return n * powl(log2l(n), c * sqrtl(2.0)) / p / 1e9 + s * (1 + 1 / c) / v;
	};

	ld b = 1e-9, e = 50;
	for (int it = 150; it--; )
	{
		ld k = (e - b) / 3.0;
		ld m1 = b + k;
		ld m2 = b + 2*k;

		ld f1 = f(m1);
		ld f2 = f(m2);
		if (f1 < f2 || f2 > 1e60)
			e = m2;
		else
			b = m1;
	}

	cout.precision(10);
	cout << fixed << f(b) << " " << b << "\n";

	return 0;
}