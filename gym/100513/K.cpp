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

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<vector<int>> a(n, vector<int>(n));
		for (auto &i : a)
			for (auto &j : i)
				cin >> j, --j;

		for (int i = 0; i < n; ++i)
		{
			vector<bool> mark(n);
			for (int j = 1; j < n; ++j)
			{
				int y = a[i][j], x = i;

				bool ok = false;
				for (auto k : a[y])
				{
					if (k == x) break;
					ok |= mark[k];
				}

				if (ok) break;

				if (i < y)
					cout << i+1 << " " << y+1 << "\n";

				mark[y] = true;
			}
		}

		cout << "\n";
	}

	return 0;
}