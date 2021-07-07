#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<int> point;
#define F first
#define S second



int main()
{
	#ifdef NeverBeRed
		//freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	cin >> s;

	vector<int> f(26);
	for (auto i : s)
		++f[i-'a'];

	vector<pair<int, char>> v;
	for (int i = 0; i < 26; ++i)
		if (f[i])
			v.push_back({ f[i], 'a'+i });

	sort(v.rbegin(), v.rend());

	int n = s.length() / 2;
	if (v.size() == 1
			|| (v.size() == 2
					&& ((n >= 2 && v[1].F == 1)
							|| (n >= 3 && v[1].F == 2))))
	{
		cout << "NO\n";
		return 0;
	}

	string ans = "";
//	if (v.size() == 2 && v[0].F == n)
//	{
//		ans = string(n-1, v[0].S) + string(1, v[1].S) + string(1, v[0].S) + string(n-1, v[1].S);
//	}
//	else
	{
		if (v[0].F > n)
		{
			ans = string(n, v[0].S) + string(1, v[1].S);
			v[0].F -= n;
			v[1].F -= 1;
			//swap(v[0], v[1]);
		}
		for (auto i : v)
			ans += string(i.F, i.S);
	}

	cout << "YES\n" << ans << "\n";

	return 0;
}