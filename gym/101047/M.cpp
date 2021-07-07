#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715;
#endif
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second

int mov[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

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
		string s;
		cin >> s;

		set<int> d;
		for (auto &i : s)
			if (i == 'D')
				d.insert(&i-&s[0]);

		vector<int> ans;
		while (!d.empty())
		{
			int x = *d.begin();
			d.erase(d.begin());
			ans.push_back(x);

			s[x] = '#';
			if (x > 0 && s[x-1] != '#')
			{
				if (s[x-1] == 'D')
				{
					s[x-1] = 'B';
					d.erase(x-1);
				}
				else
				{
					s[x-1] = 'D';
					d.insert(x-1);
				}
			}

			if (x+1 < n && s[x+1] != '#')
			{
				if (s[x+1] == 'D')
				{
					s[x+1] = 'B';
					d.erase(x+1);
				}
				else
				{
					s[x+1] = 'D';
					d.insert(x+1);
				}
			}
		}

		if (ans.size() == n)
		{
			cout << "Y\n";
			for (auto &i : ans)
				cout << i+1 << " \n"[&i==&ans.back()];
		}
		else
			cout << "N\n";
	}

	return 0;
}