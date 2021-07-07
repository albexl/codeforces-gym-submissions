#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

ll obtain(string &s)
{
	ll x = 0, p = -10000;
	for(auto &c : s)
	{
		if(c == '.') p = 0;
		else x = 10 * x + (c - '0'), ++p;
	}

	p = max(p, 0ll);

	while(p < 7) x *= 10, ++p;

	return x;
}

ll gett(string s)
{
	if(find(s.begin(), s.end(), '.') != s.end())
	{
		string t = "";
		for(int i = (int)s.size() - 1, j = 0; i >= 0; --i)
		{
			if(!j && s[i] == '0') continue;
			else j = 1, t += s[i];
		}
		reverse(t.begin(), t.end());
		s = t;
	}

	ll x = 0;
	for(auto &c : s)
		if(c != '.') x = 10 * x + (c - '0');

	return x;
}

ll min_div(ll x)
{
	for(ll i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return i;
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int c;
	cin >> c;

	while(c--)
	{
		string s, t;
		cin >> s >> t;

		ll a = obtain(s), b = obtain(t);
		if(a == b)
		{
			cout << "2 2" << endl;
			continue;
		}

		ll g = __gcd(a, b);
		a /= g;
		b /= g;

		if(a == min_div(a) && b == min_div(b))
		{
			if(a == 1 || b == 1)
				cout << "impossible" << endl;
			else
				cout << a << " " << b << endl;
		}
		else
			cout << "impossible" << endl;
	}

	return 0;
}