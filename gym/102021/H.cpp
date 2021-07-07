#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

pair<bool, ll> is3(ll x)
{
	ll l = 0, r = 1e6;
	while(l + 1 < r)
	{
		ll m = (l + r) >> 1;
		ll f = m * (m + 1) * (2 * m + 1) / 6;
		if(f <= x) l = m;
		else r = m;
	}

	return {l * (l + 1) * (2 * l + 1) / 6 == x, l};
}

pair<bool, ll> ok(ll x, ll d)
{
	ll i = 1, s = 0;
	while(s < x)
	{
		bool good = true;
		ll x = 1;
		for(ll j = 1; j < d; ++j)
		{
			if((double)x * i > 1e17)
			{
				good = false;
				break;
			}
			x *= i;
		}

		if(!good) break;
		s += x;
		++i;
	}

	return {s == x, i - 1};
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	auto x = is3(n);
	if(x.first)
	{
		cout << "3 " << x.second << endl;
		return 0;
	}
	else
	{
		for(ll i = 4; ; ++i)
		{
			 if (clock() >= 0.9*CLOCKS_PER_SEC) break;
			 x = ok(n, i);
			 if(x.first)
			 {
				 cout << i << " " << x.second << endl;
				 return 0;
			 }
		}
	}

	cout << "impossible" << endl;

	return 0;
}