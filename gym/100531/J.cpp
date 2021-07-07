#include <bits/stdc++.h>

using namespace std;

#ifdef Adrian
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second
#define ii pair<ll,ll>

struct pt
{
	ll x,y;
	pt(ll _x, ll _y):x(_x),y(_y){}
	pt operator +(pt other)
	{
		return pt(x+other.x, y+other.y);
	}
	pt operator -(pt other)
	{
		return pt (x- other.x, y-other.y);
	}
	ll lenght()
	{
		return x*x + y*y;
	}
	pt operator *(ll other)
	{
		return pt(x*other, y*other);
	}
};

int main()
{
	//#ifdef Adrian
		freopen("joy.in", "r", stdin);
		freopen("joy.out", "w", stdout);
	//#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	ll Bx, By, Fx, Fy;
	cin>>Bx>>By>>Fx>>Fy;

	ll n,k,vmax;
	cin>>n>>k>>vmax;

	pt end(Bx,By);

	vector<ll> times;
	vector<pt> vec;
	ll px,py;
	for(int i=0; i<=n; i++)
	{
		ll t,x,y;
		if(i<n)
			cin>>t>>x>>y;
		else
			t = k;

		if(times.size())
		{
			for(ll j = 1; j<=t - times.back(); j++)
			{
				end = end + pt(px,py);
				vec.push_back(end);
			}
		}
		px = x;
		py = y;
		times.push_back(t);
	}

	end = pt(Fx,Fy) - end;

	if(end.lenght() > (ll)k * k * vmax * vmax)
	{
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes"<<'\n';

	cout.precision(15);
	cout<<fixed;
	for(ll i = 1; i<=k; i++)
	{
		ld x = ((ld)(end.x * i)) / k + vec[i-1].x;
		ld y = ((ld)(end.y * i)) / k + vec[i-1].y;

		cout<<x<<" "<<y<<'\n';
	}

	return 0;
}