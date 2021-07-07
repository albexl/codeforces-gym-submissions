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
typedef complex<ll> point;
#define F first
#define S second

int get(char x)
{
	if ('a' <= x && x <= 'z')
		return x - 'a' + 1;
	return x - 'A' + 28;
}

int main()
{

	//#ifdef DGC
		freopen("boolean.in", "r", stdin);
		freopen("boolean.out", "w", stdout);
	//#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	cin >> s;

	vector<int> a;

	int n = s.length();
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '~')
		{
			int x = get(s[i+1]);
			a.push_back(-x);
			i += 2;
		}
		else
		{
			int x = get(s[i]);
			a.push_back(x);
			++i;
		}
	}

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());

	n = a.size();

	set<int> mp, mp2;
	for (auto i : a)
	{
		mp.insert(i);
		mp2.insert(abs(i));
	}

	for (auto i : a)
		if (mp.find(-i) != mp.end())
		{
			cout << (1LL << mp2.size()) << "\n";
			return 0;
		}

	cout << (1LL << mp2.size()) - 1 << "\n";

	return 0;
}