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

	int n;
	cin >> n;
	vector<ll> v;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		if (s.length() > 8 || s[0] == '-') continue;
		v.push_back(atoll(s.data()));
	}

	sort(v.begin(), v.end());
	v.push_back(numeric_limits<ll>::max());
	for (int i = 0; ; ++i)
	{
		if (v[i] == i) continue;
		cout << i << "\n";
		break;
	}

//	const ll M = 1LL<<40;
//	ll s = 1611516670LL;
//
//	cout << "0 " << (s&1) << "\n";
//	for (int i = 1; i < 10; ++i)
//	{
//		s = (s + (s >> 20) + 12345) % M;
//		cout << i << " " << (s&1) << "\n";
//	}

	return 0;
}