#include <bits/stdc++.h>

using namespace std;

#ifdef Adrian
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second
const double EPS=1e-8,oo=1e9;

struct fraction
{
	ll x,y;
	fraction(ll _x, ll _y)
	{
		ll g = __gcd(_x,_y);
		x = _x / g;
		y = _y / g;
	}
	bool operator <(const fraction other)const
	{
		return x * other.y < y * other.x;
	}
	fraction operator -(fraction other)
	{
		return fraction(other.y * x - other.x * y, y * other.y);
	}
	fraction operator +(fraction other)
	{
		return fraction(other.y * x + other.x * y, y * other.y);
	}
	void print()
	{
		cout<<x<<"/"<<y<<'\n';
	}
};

void generate(vector<fraction> &v, ll pos, fraction f)
{
	if(f.x != 0)
		v.push_back(f);
	if(pos == 14) return;
	for(ll i = 0; i<pos; i++)
	{
		fraction temp = f + fraction(i,pos);
		if(temp < fraction(1,1))
			generate(v, pos + 1, temp);
	}
}

int main()
{
	freopen("zanzibar.in", "r", stdin);

	ios_base::sync_with_stdio(0), cin.tie(0);

	vector<fraction> v;
	generate(v, 2, fraction(0, 1));
	v.push_back(fraction(1,1));
	v.push_back(fraction(0,1));

	sort(v.begin(), v.end());

	int t;
	cin>>t;
	for(int c = 1; c<=t; c++)
	{
		ll x,y;
		cin>>x>>y;
		fraction f(x,y);
		int pos = lower_bound(v.begin(), v.end(), f) - v.begin();

		fraction ans = v[pos] - f;
		if(pos != 0)
			ans = min(ans, f - v[pos - 1]);

		cout<<"Case "<<c<<": ";
		ans.print();
	}

	return 0;
}