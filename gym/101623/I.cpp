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

struct obj
{
	int d, s, id;

	bool operator <(const obj &x) const
	{
		if (d > s && x.d > x.s)
		{
			return max(d, s+x.d) < max(x.d, x.s+d);
		}
		return make_pair(d <= s, s) < make_pair(x.d <= x.s, x.s);
	}
};

struct info
{
	int i, j, id;
};

int main()
{
	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, w;
	cin >> n >> w;

	vector<obj> a(n);
	for (auto &i : a)
	{
		cin >> i.d >> i.s;
		i.id = &i-&a[0] + 1;
	}

	sort(a.begin(), a.end());

	vector<int> dp(w+1, -(1<<30));
	vector<vector<info>> go(w+1);

	dp[0] = 0;

	for (auto x : a)
		for (int i = w; i >= 0; --i)
			if (i + max(x.d, x.s) <= w)
			{
				if (dp[i] + 1 > dp[i + x.s])
				{
					dp[i + x.s] = dp[i] + 1;
					go[i + x.s].push_back({ i, go[i].size() - 1, x.id });
				}
			}

	int p = max_element(dp.begin(), dp.end()) - dp.begin();
	cout << dp[p] << "\n";

	debug(p)

	int j = go[p].size() - 1;
	vector<int> ans;
	while (p > 0)
	{
		ans.push_back(go[p][j].id);
		tie(p, j) = make_pair(go[p][j].i, go[p][j].j);
	}

	reverse(ans.begin(), ans.end());
	for (auto &i : ans)
		cout << i << " \n"[&i==&ans.back()];

	return 0;
}