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

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;

	map<int, int> mp;
	for (int i = 0; i < 256; ++i)
	{
		int x = i ^ (i << 1);
		x &= 255;
		assert(mp.find(x) == mp.end());
		mp[x] = i;
	}

	for (auto &i : a)
		cout << mp[i] << " \n"[&i==&a.back()];

	return 0;
}