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
	//#ifdef DGC
		freopen("ghanophobia.in", "r", stdin);
		//freopen("b.out", "w", stdout);
	//#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;

	for (int t = 1; t <= n; ++t)
	{
		string s;
		cin >> s;

		int i = 0;
		while (s[i] != ':') ++i;

		int a = atoi(s.substr(0, i).data());
		int b = atoi(s.substr(i+1, s.length()-i-1).data());

		if (a+1 == b+6)
		{
			a = a + 2;
			b = 2*b + 6;
		}
		else
		{
			a += 1;
			b += 6;
		}

		cout << "Case " << t << ": ";
		if (a > b)
			cout << "YES\n";
		if (a == b)
			cout << "PENALTIES\n";
		if (a < b)
			cout << "NO\n";
	}

	return 0;
}