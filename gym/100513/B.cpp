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

	int n, k;
	cin >> n >> k;
	map<int, vector<int>> mp;
	vector<int> com;
	for (int i = 0, x; i < n; ++i)
	{
		cin >> x;
		if (x != -1)
			mp[x].push_back(i);
		else
			com.push_back(i);
	}

	set<pair<int, int>> s;
	for (auto &i : mp)
		s.insert({ i.S.size(), i.F });

	vector<pair<int, int>> ans(n, make_pair(1, 1));

	int cnt = 0, g = n/k;
	while (!s.empty())
	{
		++cnt;

		if (cnt > k) break;

		auto p1 = *s.begin();
		s.erase(s.begin());

		if (p1.F >= g || s.empty())
		{
			auto &t = mp[p1.S];
			for (int j = min(g, p1.F); j--; )
			{
				ans[t.back()] = { p1.S, 1 };
				t.pop_back();
			}

			for (int j = g - min(g, p1.F); j--; )
			{
				if (com.empty()) { cnt = 1e9; break; }
				ans[com.back()] = { p1.S, 1 };
				com.pop_back();
			}

			p1.F -= min(p1.F, g);
			if (p1.F > 0)
				s.insert(p1);

			continue;
		}

		auto it = s.lower_bound({ g - p1.F, 0 });
		if (it == s.end()) it = prev(it);

		auto p2 = *it;
		s.erase(it);

		auto &t = mp[p1.S];
		for (int j = p1.F; j--; )
		{
			ans[t.back()] = { p1.S, p2.S };
			t.pop_back();
		}

		auto &t2 = mp[p2.S];
		for (int j = min(g-p1.F, p2.F); j--; )
		{
			ans[t2.back()] = { p1.S, p2.S };
			t2.pop_back();
		}

		for (int j = g - min(g-p1.F, p2.F) - p1.F; j--; )
		{
			if (com.empty()) { cnt = 1e9; break; }
			ans[com.back()] = { p1.S, p2.S };
			com.pop_back();
		}

		p2.F -= min(g-p1.F, p2.F);
		if (p2.F > 0)
			s.insert(p2);
	}

	if (cnt <= k)
	{
		cout << "Yes\n";
		for (auto i : ans)
			cout << i.F << " " << i.S << "\n";
	}
	else
		cout << "No\n";

	return 0;
}